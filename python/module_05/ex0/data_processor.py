#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self.new_list: list[tuple[int, str]] = []
        self.valid: bool = False
        self.index: int = 0
        self.expected_type: type | tuple[type, ...]
        self.message: str = ""

    @abstractmethod
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        self.valid = all(isinstance(item, self.expected_type) for item in self.data)
        return self.valid

    @abstractmethod
    def ingest(self, data: Any) -> None:
        if not self.valid:
            print(f"Test invalid ingestion of {type(data).__name__} "
                  f"'{data}' without prior validation:")

            if not self.validate(data):
                raise ValueError(self.message)
        print(f"Processing data: {data}")
        self.valid = False

    def output(self) -> tuple[int, str]:
        if not self.new_list:
            raise IndexError("No more data to output")
        return self.new_list.pop(0)


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.expected_type = (int, float)
        return super().validate(data)

    def ingest(self, data: int | float | list[int | float]) -> None:
        self.message = "Improper numeric data"
        super().ingest(data)
        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.index += 1


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.expected_type = str
        return super().validate(data)

    def ingest(self, data: str | list[str]) -> None:
        self.message = "Improper text data"
        super().ingest(data)
        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.index += 1


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.expected_type = dict
        return super().validate(data)

    def ingest(self, data: dict | list[dict]) -> None:
        self.message = "Improper numeric data"
        super().ingest(data)
        for item in self.data:
            self.new_list.append((self.index, f"{item['log_level']}: "
                                  f"{item['log_message']}"))
            self.index += 1


def test_numeric_proc() -> None:

    print("Testing Numeric Processor...")

    num_proc = NumericProcessor()
    print(f"Trying to validate input '42': {num_proc.validate(42)}")
    print(f"Trying to validate input 'Hello': {num_proc.validate('Hello')}")

    try:
        num_proc.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")

    num_proc.validate([1, 2, 3, 4, 5])

    try:
        num_proc.ingest([1, 2, 3, 4, 5])
    except ValueError as e:
        print(f"Got exception: {e}")

    print("Extracting 3 values...")
    try:
        for item in range(0, 3):
            output = num_proc.output()
            print(f"Numeric value {output[0]}: {output[1]}")
    except IndexError as e:
        print(e)


def test_text_proc() -> None:
    print("Testing Text Processor...")

    txt_proc = TextProcessor()
    print(f"Trying to validate input '42': {txt_proc.validate(42)}")
    txt_proc.validate(['Hello', 'Nexus', 'World'])

    try:
        txt_proc.ingest(['Hello', 'Nexus', 'World'])
    except ValueError as e:
        print(f"Got exception: {e}")

    print("Extracting 1 value...")

    try:
        output = txt_proc.output()
        print(f"Text value {output[0]}: {output[1]}")
    except IndexError as e:
        print(e)


def test_dict_proc() -> None:
    print("Testing Log Processor...")

    dict_proc = LogProcessor()
    print(f"Trying to validate input 'Hello': {dict_proc.validate('Hello')}")

    log = [{'log_level': 'NOTICE', 'log_message': 'Connection to server'},
           {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}]

    dict_proc.validate(log)

    try:
        dict_proc.ingest(log)
    except ValueError as e:
        print(f"Got exception: {e}")

    print("Extracting 2 values...")

    try:
        for item in range(0, 2):
            output = dict_proc.output()
            print(f"Log entry {output[0]}: {output[1]}")
    except IndexError as e:
        print(e)


def main() -> None:
    print("=== Code Nexus - Data Processor ===\n")

    test_numeric_proc()
    print()
    test_text_proc()
    print()
    test_dict_proc()


if __name__ == "__main__":
    main()

#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self.new_list: list[tuple[int, str]] = []
        self.valid: bool = False
        self.index: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self.new_list:
            raise IndexError("No more data to output")
        return self.new_list.pop(0)


class NumericProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        self.valid = all(isinstance(item, (int, float)) for item in self.data)
        return self.valid

    def ingest(self, data: Any) -> None:
        if not self.valid:
            print(f"Test invalid ingestion of {type(data).__name__} "
                  f"'{data}' without prior validation:")

            temp_data = [data] if not isinstance(data, list) else data
            if not all(isinstance(item, (int, float)) for item in temp_data):
                raise ValueError("Improper numeric data")

            self.data = temp_data

        print(f"Processing data: {data}")
        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.index += 1
        self.valid = False


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        self.valid = all(isinstance(item, str) for item in self.data)
        return self.valid

    def ingest(self, data: Any) -> None:
        if not self.valid:
            print(f"Test invalid ingestion of {type(data).__name__} "
                  f"'{data}' without prior validation:")
            temp_data = [data] if not isinstance(data, list) else data
            if not all(isinstance(item, str) for item in temp_data):
                raise ValueError("Improper text data")

            self.data = temp_data

        print(f"Processing data: {data}")
        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.index += 1
        self.valid = False


class LogProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        self.valid = all(isinstance(item, dict) for item in self.data)
        return self.valid

    def ingest(self, data: Any) -> None:
        if not self.valid:
            print(f"Test invalid ingestion of {type(data).__name__} "
                  f"'{data}' without prior validation:")
            temp_data = [data] if not isinstance(data, list) else data
            if not all(isinstance(item, dict) for item in temp_data):
                raise ValueError("Improper dict data")

            self.data = temp_data

        print(f"Processing data: {data}")
        for item in self.data:
            self.new_list.append((self.index, f"{item['log_level']}: "
                                  f"{item['log_message']}"))
            self.index += 1
        self.valid = False


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

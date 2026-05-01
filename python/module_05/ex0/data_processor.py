#!/usr/bin/env python3
 
from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if self.new_list:
            return self.new_list.pop(0)


class NumericProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, (int, float)) for item in self.data)

        return valid

    def ingest(self, data: int | float) -> None:
        try:
            if self.validate(data):
                print(f"Processing data: {data}")
                self.new_list += [(self.data.index(x), str(x)) for x in self.data]
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper numeric data")


class TextProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, str) for item in self.data)

        return valid

    def ingest(self, data: str | list[str]) -> None:
        try:
            if self.validate(data):
                print(f"Processing data: {data}")
                self.new_list += [(self.data.index(x), str(x)) for x in self.data]
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper text data")


class LogProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, dict) for item in self.data)
        print(item for item in self.data)

        return valid

    def ingest(self, data: dict | list[dict]) -> None:
        try:
            if self.validate(data):
                print(f"Processing data: {data}")
                self.new_list += [(self.data.index(x), dict(x)) for x in self.data]
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper dictionary data")


def main() -> None:
    print("=== Code Nexus - Data Processor ===\n")

    print("Testing Numeric Processor...")

    num_proc = NumericProcessor()
    print(f"Trying to validate input '42': {num_proc.validate(42)}")
    print(f"Trying to validate input 'Hello': {num_proc.validate('Hello')}")
    num_proc.ingest('foo')
    num_proc.ingest([1, 2, 3, 4, 5])

    print("Extracting 3 values...")
    for item in range(0, 3):
        output = num_proc.output()
        print(f"Numeric value {output[0]}: {output[1]}")

    print()
    print("Testing Text Processor...")
    
    txt_proc = TextProcessor()
    print(f"Trying to validate input '42': {txt_proc.validate(42)}")
    txt_proc.ingest(['Hello', 'Nexus', 'World'])

    print("Extracting 1 value...")
    output = txt_proc.output()
    print(f"Text value {output[0]}: {output[1]}\n")

    print()
    print("Testing Log Processor...")
    
    dict_proc = LogProcessor()
    print(f"Trying to validate input 'Hello': {dict_proc.validate('Hello')}")
    dict_proc.ingest([{'log_level': 'NOTICE', 'log_message': 'Connection to server'}, {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'}])

    print("Extracting 2 values...")
    for item in range(0, 2):
        output = dict_proc.output()
        print(f"Log entry {output[0]}: {output[1]['log_level']}: {output[1]['log_message']}")


if __name__ == "__main__":
    try:
        main()
    except Exception:
        exit
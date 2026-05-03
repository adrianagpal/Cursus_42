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

    def stats(self) -> str:
        return f"{self.__class__.__name__}: total {self.processed} items processed, remaining {len(self.new_list)} on processor"


class DataStream():

    def __init__(self):
        self.processors = []

    def register_processor(self, proc: DataProcessor) -> None:
        if isinstance(proc, DataProcessor):
            self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
    
        for element in stream:
            handled = False
            for processor in self.processors:
                if processor.validate(element):
                    processor.ingest(element)
                    handled = True
                    break
            if not handled:
                print(f"DataStream error - Can't process element in stream: {element}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if self.processors:
            for processor in self.processors:
                print(processor.stats())
            print()
        else:
            print("No processor found, no data\n")


class NumericProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        self.processed = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, (int, float)) for item in self.data)

        return valid

    def ingest(self, data: int | float) -> None:
        try:
            if self.validate(data):
                self.new_list += [(self.data.index(x), str(x)) for x in self.data]
                self.processed += len(self.data)
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper numeric data")


class TextProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        self.processed = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, str) for item in self.data)

        return valid

    def ingest(self, data: str | list[str]) -> None:
        try:
            if self.validate(data):
                self.new_list += [(self.data.index(x), str(x)) for x in self.data]
                self.processed += len(self.data)
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper text data")


class LogProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        self.processed = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, dict) for item in self.data)

        return valid

    def ingest(self, data: dict | list[dict]) -> None:
        try:
            if self.validate(data):
                print(f"Processing data: {data}")
                self.new_list += [(self.data.index(x), f"{x['log_level']}: {x['log_message']}") for x in self.data]
                self.processed += len(self.data)
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper dictionary data")


def main() -> None:
    print("=== Code Nexus - Data Stream ===\n")

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.register_processor("")
    stream.print_processors_stats()

    print("Registering Numeric Processor\n")
    num_proc = NumericProcessor()
    stream.register_processor(num_proc)

    first_batch =  ['Hello world', [3.14, -1, 2.71], 
                    [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'}, 
                    {'log_level': 'INFO', 'log_message': 'User wil is connected'}], 42, ['Hi', 'five']]

    print(f"Send first batch of data on stream: {first_batch}")    
    stream.process_stream(first_batch)
    stream.print_processors_stats()

    print("Registering other data processors")
    txt_proc = TextProcessor()
    dict_proc = LogProcessor()

    stream.register_processor(txt_proc)
    stream.register_processor(dict_proc)

    print("Send the same batch again")
    stream.process_stream(first_batch)
    stream.print_processors_stats()

    print("Consume some elements from the data processors: Numeric 3, Text 2, Log 1")
    for item in range(0, 3):
        num_proc.output()

    for item in range(0, 2):
        txt_proc.output()
    
    dict_proc.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()
#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):

    def __init__(self) -> None:
        self.new_list: list[tuple[int, str]] = []
        self.valid: bool = False
        self.index: int = 0
        self.processed: int = 0

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

    def stats(self) -> str:
        return (f"{self.__class__.__name__}: total {self.processed} items "
                f"processed, remaining {len(self.new_list)} on processor")


class DataStream():

    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

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
                print(f"DataStream error - "
                      f"Can't process element in stream: {element}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if self.processors:
            for processor in self.processors:
                print(processor.stats())
            print()
        else:
            print("No processor found, no data\n")


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

        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.processed += 1
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

        for item in self.data:
            self.new_list.append((self.index, str(item)))
            self.processed += 1
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

        for item in self.data:
            self.new_list.append((self.index, f"{item['log_level']}: "
                                  f"{item['log_message']}"))
            self.index += 1
            self.processed += 1
        self.valid = False


def main() -> None:
    print("=== Code Nexus - Data Stream ===\n")

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()

    print("Registering Numeric Processor\n")
    num_proc = NumericProcessor()
    stream.register_processor(num_proc)

    first_batch = ['Hello world', [3.14, -1, 2.71],
                   [{'log_level': 'WARNING',
                     'log_message': 'Telnet access! Use ssh instead'},
                    {'log_level': 'INFO',
                     'log_message': 'User wil is connected'}
                    ], 42, ['Hi', 'five']]

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

    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    try:
        for item in range(0, 3):
            num_proc.output()

        for item in range(0, 2):
            txt_proc.output()
    except IndexError as e:
        print(e)

    dict_proc.output()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()

#!/usr/bin/env python3

from abc import ABC, abstractmethod
from typing import Any, Protocol


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


class ExportPlugin(Protocol):

    @abstractmethod
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVExportPlugin(ExportPlugin):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        new_list = [item[1] for item in data]
        csv_result = ','.join(new_list)
        print(csv_result)


class JSONExportPlugin(ExportPlugin):

    def process_output(self, data: list[tuple[int, str]]) -> None:
        new_dict = {f"item_{item[0]}": item[1] for item in data}
        print(new_dict)


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

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self.processors:
            new_list: list[tuple[int, str]] = []
            for element in range(0, nb):
                if processor.new_list:
                    new_list.append(processor.output())

            if type(plugin) is CSVExportPlugin:
                print("CSV Output:")
            elif type(plugin) is JSONExportPlugin:
                print("JSON Output:")
            plugin.process_output(new_list)

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
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...\n")
    stream = DataStream()
    stream.print_processors_stats()

    print("Registering Processors\n")
    num_proc = NumericProcessor()
    txt_proc = TextProcessor()
    dict_proc = LogProcessor()

    stream.register_processor(num_proc)
    stream.register_processor(txt_proc)
    stream.register_processor(dict_proc)

    first_batch = ['Hello world', [3.14, -1, 2.71],
                   [{'log_level': 'WARNING',
                     'log_message': 'Telnet access! Use ssh instead'},
                    {'log_level': 'INFO',
                     'log_message': 'User wil is connected'}
                    ], 42, ['Hi', 'five']]

    print(f"Send first batch of data on stream: {first_batch}\n")

    stream.process_stream(first_batch)
    stream.print_processors_stats()

    print("Send 3 processed data from each processor to a CSV plugin:")
    csv_plugin = CSVExportPlugin()
    stream.output_pipeline(3, csv_plugin)

    print()
    stream.print_processors_stats()

    second_batch = [21, ['I love AI', 'LLMs are wonderful', 'Stay healthy'],
                    [{'log_level': 'ERROR', 'log_message': '500 server crash'},
                     {'log_level': 'NOTICE',
                      'log_message': 'Certificate expires in 10 days'}
                     ], [32, 42, 64, 84, 128, 168], 'World hello']

    print(f"Send another batch of data: {second_batch}\n")

    stream.process_stream(second_batch)
    stream.print_processors_stats()

    print("Send 5 processed data from each processor to a CSV plugin:")
    json_plugin = JSONExportPlugin()
    stream.output_pipeline(5, json_plugin)

    print()
    stream.print_processors_stats()


if __name__ == "__main__":
    main()

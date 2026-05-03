#!/usr/bin/env python3
 
from abc import ABC, abstractmethod
from typing import Any
from typing import Protocol


class DataProcessor(ABC):
    
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
        return f"{self.__class__.__name__}: total {self.processed} items processed, remaining {len(self.new_list)} on processor"


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
        new_dict = {f"item_{item[0]}":item[1] for item in data}
        print(new_dict)


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

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        
        for processor in self.processors:
            new_list = []
            for element in range(0, nb):
                if processor.new_list:
                    new_list.append(processor.output())

            if type(plugin) == CSVExportPlugin:
                print("CSV Output:")
            elif type(plugin) == JSONExportPlugin:
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

    def __init__(self):
        self.new_list = []
        self.processed = 0
        self.index = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, (int, float)) for item in self.data)

        return valid

    def ingest(self, data: int | float) -> None:
        try:
            if self.validate(data):
                for item in self.data:
                    self.new_list.append((self.index, str(item)))
                    self.index += 1
                    self.processed += 1
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper numeric data")


class TextProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        self.processed = 0
        self.index = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, str) for item in self.data)

        return valid

    def ingest(self, data: str | list[str]) -> None:
        try:
            if self.validate(data):
                for item in self.data:
                    self.new_list.append((self.index, str(item)))
                    self.index += 1
                    self.processed += 1
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper text data")


class LogProcessor(DataProcessor):

    def __init__(self):
        self.new_list = []
        self.processed = 0
        self.index = 0
        
    def validate(self, data: Any) -> bool:
        self.data = [data] if not isinstance(data, list) else data
        valid = all(isinstance(item, dict) for item in self.data)

        return valid

    def ingest(self, data: dict | list[dict]) -> None:
        try:

            if self.validate(data):
                for item in self.data:
                    self.new_list.append((self.index, f"{item['log_level']}: {item['log_message']}"))
                    self.index += 1
                    self.processed += 1
            else:
                print(f"Test invalid ingestion of {type(data).__name__} '{data}' without prior validation:")
                raise Exception()
        except Exception:
            print("Got exception: Improper dictionary data")


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===\n")

    print("Initialize Data Stream...\n")
    stream = DataStream()
    stream.register_processor("")
    stream.print_processors_stats()

    print("Registering Processors\n")
    num_proc = NumericProcessor()
    txt_proc = TextProcessor()
    dict_proc = LogProcessor()

    stream.register_processor(num_proc)
    stream.register_processor(txt_proc)
    stream.register_processor(dict_proc)

    first_batch =  ['Hello world', [3.14, -1, 2.71], 
                    [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'}, 
                    {'log_level': 'INFO', 'log_message': 'User wil is connected'}], 42, ['Hi', 'five']]

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
    {'log_level': 'NOTICE', 'log_message': 'Certificate expires in 10 days'}], 
    [32, 42, 64, 84, 128, 168], 'World hello']

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
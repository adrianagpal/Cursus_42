import typing
import abc


class DataProcessor(ABC):
    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        return self.new_list


class NumericProcessor(DataProcessor):

    def __init__(self):
        
    def validate(self, data: Any) -> bool:
        if all(isinstance(item, (int, float)) for item in data):
            return True
        return False

    def ingest(self, data: int | float) -> None:
        self.new_list = [str(x) for x in data]


class TextProcessor(DataProcessor):

    def validate(self, data: Any) -> bool:
        if all(isinstance(item, str) for item in data):
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:


class LogProcessor(DataProcessor):
    
    def validate(self, data: Any) -> bool:
        if all(isinstance(item, dict) for item in data):
            return True
        return False

    def ingest(self, data: Any) -> None:

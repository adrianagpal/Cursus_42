from abc import abstractmethod
from typing import Protocol


class CanAttack(Protocol):
    name: str

    @abstractmethod
    def attack(self) -> str:
        pass


class CanHeal(CanAttack):

    @abstractmethod
    def heal(self) -> str:
        pass


class CanTransform(CanAttack):

    @abstractmethod
    def transform(self) -> str:
        pass

    @abstractmethod
    def revert(self) -> str:
        pass

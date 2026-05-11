from typing import Protocol


class CanAttack(Protocol):
    name: str
    def attack(self) -> str: ...


class CanHeal(CanAttack, Protocol):
    def heal(self) -> str: ...


class CanTransform(CanAttack, Protocol):
    def transform(self) -> str: ...
    def revert(self) -> str: ...

from abc import ABC, abstractmethod
from typing import TypeVar, Generic
from .protocol import CanAttack, CanTransform, CanHeal


T = TypeVar("T")


class BattleStrategy(Generic[T], ABC):

    def __init__(self) -> None:
        super().__init__()

    @abstractmethod
    def act(self, creature: T) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: T) -> bool:
        pass


class NormalStrategy(BattleStrategy[CanAttack]):

    def is_valid(self, creature: CanAttack) -> bool:
        return (hasattr(creature, "attack"))

    def act(self, creature: CanAttack) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this normal strategy")

        print(creature.attack())


class AggressiveStrategy(BattleStrategy[CanTransform]):

    def is_valid(self, creature: CanTransform) -> bool:
        return all([
            hasattr(creature, "attack"),
            hasattr(creature, "transform"),
            hasattr(creature, "revert")
        ])

    def act(self, creature: CanTransform) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this aggressive strategy")

        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStrategy[CanHeal]):

    def is_valid(self, creature: CanHeal) -> bool:
        return all([
            hasattr(creature, "attack"),
            hasattr(creature, "heal")
        ])

    def act(self, creature: CanHeal) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this defensive strategy")

        print(creature.attack())
        print(creature.heal())

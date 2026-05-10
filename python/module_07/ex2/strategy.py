from abc import ABC, abstractmethod
from ex0.creature import Creature


class BattleStrategy(ABC):

    def __init__(self) -> None:
        super().__init__()

    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return (hasattr(creature, "attack"))

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this normal strategy")

        print(creature.attack())


class AggressiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return all([
            hasattr(creature, "attack"),
            hasattr(creature, "transform"),
            hasattr(creature, "revert")
        ])

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this aggressive strategy")

        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStrategy):

    def is_valid(self, creature: Creature) -> bool:
        return all([
            hasattr(creature, "attack"),
            hasattr(creature, "heal")
        ])

    def act(self, creature: Creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} "
                            "for this defensive strategy")

        print(creature.attack())
        print(creature.heal())

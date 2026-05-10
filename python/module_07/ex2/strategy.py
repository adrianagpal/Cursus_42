from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1.capability import HealCapability, TransformCapability


class BattleStrategy(ABC):

    def __init__(self) -> None:
        super().__init__()

    @abstractmethod
    def act(self, creature) -> None:
        pass

    @abstractmethod
    def is_valid(self, creature) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(hasattr(creature, "attack"))
    
    def act(self, creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} for this normal strategy")
        
        print(creature.attack())


class AggressiveStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(
            hasattr(creature, "attack") and
            hasattr(creature, "transform") and
            hasattr(creature, "revert")
        )
    
    def act(self, creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} for this aggressive strategy")
        
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(
            hasattr(creature, "attack") and
            hasattr(creature, "heal")
        )
    
    def act(self, creature) -> None:
        if not self.is_valid(creature):
            raise Exception(f"Invalid Creature {creature.name!r} for this defensive strategy")
        
        print(creature.attack())
        print(creature.heal())

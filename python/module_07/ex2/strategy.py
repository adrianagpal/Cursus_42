from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1 import HealCapability, TransformCapability


class BattleStrategy(ABC):

    def __init__(self) -> None:
        super().__init__()

    @abstractmethod
    def act(self):
        pass

    def is_valid(self) -> bool:
        pass


class NormalStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(hasattr(creature, "attack"))
    
    def act(self, creature, opponent) -> None:
        if not self.valid(creature):
            raise Exception("NormalStrategy requires attack capability")
        
        creature.attack(opponent)


class AggressiveStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(
            hasattr(creature, "attack") and
            hasattr(creature, "transform") and
            hasattr(creature, "revert")
        )
    
    def act(self, creature, opponent) -> None:
        if not self.valid(creature):
            raise Exception("AggressiveStrategy requires attack, transform and revert capabilities")
        
        creature.transform()
        creature.attack(opponent)
        creature.revert()


class DefensiveStrategy(BattleStrategy):

    def is_valid(self, creature) -> bool:
        return(
            hasattr(creature, "attack") and
            hasattr(creature, "heal")
        )
    
    def act(self, creature, opponent) -> None:
        if not self.valid(creature):
            raise Exception("DefensiveStrategy requires attack and heal capabilities")
        
        creature.attack(opponent)
        creature.heal()

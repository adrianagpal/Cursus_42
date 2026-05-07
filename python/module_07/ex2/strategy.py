from abc import ABC, abstractmethod
from ex0.creature import Creature
from ex1 import HealCapability, TransformCapability


class BattleStrategy(ABC):

    def __init__(self):
        super().__init__()

    @abstractmethod
    def act(self):
        pass

    def is_valid(self) -> bool:
        pass


class NormalStrategy(BattleStrategy, Creature):


class AggressiveStrategy(BattleStrategy, Creature, TransformCapability):


class DefensiveStrategy(BattleStrategy, Creature, HealCapability):


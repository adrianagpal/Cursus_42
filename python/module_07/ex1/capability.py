from abc import ABC, abstractmethod
from ex0.creature import Creature

class HealCapability(ABC):

    @abstractmethod
    def heal(self):
        pass


class TransformCapability(ABC):
    def __init__(self):
        self.state: str

    @abstractmethod
    def transform(self):
        pass

    @abstractmethod
    def revert(self):
        pass


class Sproutling(Creature, HealCapability):


class Bloomelle(Creature, HealCapability):


class Shiftling(Creature, TransformCapability):


class Morphagon(Creature, TransformCapability):

from abc import ABC, abstractmethod
from ex0.creature import Creature


class HealCapability(ABC):

    @abstractmethod
    def heal(self):
        pass


class TransformCapability(ABC):
    def __init__(self):
        self.transformed: bool = False

    @abstractmethod
    def transform(self):
        pass

    @abstractmethod
    def revert(self):
        pass


class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self.creature_type = "Grass"

    def attack(self) -> str:
        return f"{self.name} uses Vine Whip!"
    
    def heal(self) -> str:
        return f"{self.name} heals itself for a small amount"


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self.creature_type = "Grass/Fairy"

    def attack(self) -> str:
        return f"{self.name} uses Petal Dance!"
    
    def heal(self) -> str:
        return f"{self.name} heals itself and others for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        super().__init__()
        self.creature_type = "Normal"

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} performs a boosted strike!"
        else:
            return f"{self.name} attacks normally."

    def transform(self):
        self.transformed = True
        return f"{self.name} shifts into a sharper form!"

    def revert(self):
        self.transformed = False
        return f"{self.name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        super().__init__()
        self.creature_type = "Normal/Dragon"

    def attack(self) -> str:
        if self.transformed:
            return f"{self.name} unleashes a devastating morph strike!"
        else:
            return f"{self.name} attacks normally."
    
    def transform(self):
        self.transformed = True
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self):
        self.transformed = False
        return f"{self.name} stabilized its form."

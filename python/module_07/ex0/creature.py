from abc import ABC, abstractmethod

class Creature(ABC):
    def __init__(self):
        self.name: str = self.__class__.__name__
        self.creature_type: str
        super().__init__()

    @abstractmethod
    def attack(self) -> str:
        pass

    def describe(self) -> str:
        return f"{self.name} is a {self.creature_type} type Creature"


class Flameling(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Fire"

    def attack(self) -> str:
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Fire/Flying"

    def attack(self) -> str:
        return f"{self.name} uses Flamethrower!"


class Aquabub(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Water"

    def attack(self) -> str:
        return f"{self.name} uses Water Gun!"


class Torragon(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Water"

    def attack(self) -> str:
        return f"{self.name} uses Hydro Pump!"
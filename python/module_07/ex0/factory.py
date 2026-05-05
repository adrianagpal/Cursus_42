#!/usr/bin/env python3

from abc import ABC, abstractmethod

class Creature(ABC):
    def __init__(self):
        self.name: str = self.__class__.__name__
        self.creature_type: str

    @abstractmethod
    def attack(self):
        pass

    def describe(self):
        print(f"{self.name} is of type {self.creature_type}")


class CreatureFactory(ABC):

    @abstractmethod
    def create_base():
        pass

    @abstractmethod
    def create_evolved():
        pass


class FlameFactory(CreatureFactory):
    def create_base(self):
        creature = Flameling()
        creature.describe()
        creature.attack()

    def create_evolved(self):
        creature = Pyrodon()
        creature.describe()
        creature.attack()


class AquaFactory(CreatureFactory):
    def create_base(self):
        creature = Aquabub()
        creature.describe()
        creature.attack()

    def create_evolved(self):
        creature = Torragon()
        creature.describe()
        creature.attack()


class Flameling(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Fire"

    def attack(self):
        print(f"{self.name} uses Ember!")


class Pyrodon(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Fire/Flying"

    def attack(self):
        print(f"{self.name} uses Flamethrower!")


class Aquabub(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Water"

    def attack(self):
        print(f"{self.name} uses Water Gun!")


class Torragon(Creature):
    def __init__(self):
        super().__init__()
        self.creature_type = "Water"

    def attack(self):
        print(f"{self.name} uses Hydro Pump!")
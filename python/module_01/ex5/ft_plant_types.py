#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float = 0.0, age_days: int = 0):
        self._name = name
        if height >= 0:
            self._height = height
        if age_days >= 0:
            self._age_days = age_days
    def show(self) -> None:
        print(f"{self._name}: {round(self._height, 1)}cm, {self._age_days} days old")
    def grow(self):
        self._height += 0.8
        return self
    def age(self):
        self._age_days += 1
        return self
    def set_height(self, height: float) -> None:
        if height >= 0:
            self._height = height
            print(f"Height updated: {self._height}cm")
        else:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
    def set_age(self, age_days: int) -> None:
        if age_days >= 0:
            self._age_days = age_days
            print(f"Age updated: {self._age_days} days")
        else:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")

class Flower(Plant):
    def __init__(self, name: str, color: str, height: float = 0.0, age_days: int = 0):
        super().__init__(name, height, age_days)
        self.color = color
        self.bloomed = False

    def bloom(self):
        print("[asking the rose to bloom]")
        self.bloomed = True

    def show(self):
        super().show()
        print(f" Color: {self.color}")
        if self.bloomed == False:
            print(f" {self._name} has not bloomed yet")
        else:
            print(f" {self._name} is blooming beautifully!")

class Tree(Plant):
    def __init__(self, name: str, trunk_diameter: int, height: float = 0.0, age_days: int = 0):
        super().__init__(name, height, age_days)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self):
        print(f"[asking the {self._name} to produce shade]")
        print(f"Tree {self._name} now produces a shade of {self._height}cm long and {self._trunk_diameter}cm wide.")

    def show(self):
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter}cm")

class Vegetable(Plant):
    def __init__(self, name: str, harvest_season: str, nutritional_value: int = 0, height: float = 0.0, age_days: int = 0):
        super().__init__(name, height, age_days)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def produce_shade(self):
        print(f"[asking the {self._name} to produce shade]")
        print(f"Tree {self._name} now produces a shade of {self._height}cm long and {self._trunk_diameter}cm wide.")

    def show(self):
        super().show()
        print(f" Harvest season: {self._harvest_season}")
        print(f" Nutritional value: {self._nutritional_value}")

    def grow_age(self, nutritional_value):
        print(f"[make {self._name} grow and age for {nutritional_value} days]")
        self._nutritional_value = nutritional_value
        for count in range(1, nutritional_value + 1):
            super().grow()
            super().age()
        
if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose: Flower = Flower("Rose", "red", 15.0, 10)
    rose.show()
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak: Tree = Tree("Oak", 5.0, 200.0, 365)
    oak.show()
    oak.produce_shade()
    print()
    print("=== Vegetable")
    tomato: Vegetable = Vegetable("Tomato", "April", 0, 5.0, 10)
    tomato.show()
    tomato.grow_age(20)
    tomato.show()
#!/usr/bin/env python3

class Plant:
    def __init__(
            self, name: str,
            height: float = 0.0, days: int = 0, growth: float = 0.0) -> None:
        self._name = name
        if height >= 0:
            self._height = height
        if days >= 0:
            self._days = days
        if growth >= 0:
            self._growth = growth

    def show(self) -> None:
        print(f"{self._name}: {self._height:.1f}cm, {self._days} days old")

    def grow(self) -> "Plant":
        self._height += self._growth
        return self

    def age(self) -> "Plant":
        self._days += 1
        return self

    def set_height(self, height: float) -> None:
        if height >= 0:
            self._height = height
            print(f"Height updated: {self._height}cm")
        else:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")

    def set_age(self, days: int) -> None:
        if days >= 0:
            self._days = days
            print(f"Age updated: {self._days} days")
        else:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._days


class Flower(Plant):
    def __init__(
            self, name: str,
            color: str, height: float = 0.0,
            days: int = 0, growth: float = 0.0) -> None:
        super().__init__(name, height, days, growth)
        self._color = color
        self._bloomed = False

    def bloom(self) -> None:
        print(f"[asking the {self._name} to bloom]")
        self._bloomed = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if not self._bloomed:
            print(f" {self._name} has not bloomed yet")
        else:
            print(f" {self._name} is blooming beautifully!")


class Tree(Plant):
    def __init__(
            self, name: str,
            trunk_diameter: float,
            height: float = 0.0, days: int = 0, growth: float = 0.0) -> None:
        super().__init__(name, height, days, growth)
        self._trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(f"[asking the {self._name} to produce shade]")
        print(
            f"Tree {self._name} now produces a shade of {self._height:.1f}cm"
            f" long and {self._trunk_diameter:.1f}cm wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(
            self, name: str,
            harvest_season: str, nutritional_value: int = 0,
            height: float = 0.0, days: int = 0, growth: float = 0.0) -> None:
        super().__init__(name, height, days, growth)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self._harvest_season}")
        print(f" Nutritional value: {self._nutritional_value}")

    def grow_age(self, nutritional_value) -> None:
        print(f"[make {self._name} grow and age for {nutritional_value} days]")
        self._nutritional_value = nutritional_value
        for count in range(1, nutritional_value + 1):
            super().grow()
            super().age()


def main() -> None:
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose: Flower = Flower("Rose", "red", 15, 10)
    rose.show()
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak: Tree = Tree("Oak", 5, 200, 365)
    oak.show()
    oak.produce_shade()
    print()
    print("=== Vegetable")
    tomato: Vegetable = Vegetable("Tomato", "April", 0, 5, 10, 2.1)
    tomato.show()
    tomato.grow_age(20)
    tomato.show()


if __name__ == "__main__":
    main()

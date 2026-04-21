#!/usr/bin/env python3

class Plant:
    def __init__(
            self, name: str, height: float = 0.0, age_days: int = 0) -> None:
        self._name = name.capitalize()
        if height >= 0:
            self._height = height
        if age_days >= 0:
            self._age_days = age_days
        self.count_grow = 0
        self.count_age = 0
        self.count_show = 0
        self.count_shade = 0
        self.asked_grow = False
        self.asked_age = False

    def show(self) -> None:
        print(f"{self._name}: {self._height:.1f}cm, {self._age_days} days old")
        self.count_show += 1

    def grow(self) -> "Plant":
        self.asked_grow = True
        self._height += 0.8
        self.count_grow += 1
        return self

    def age(self) -> "Plant":
        self.asked_age = True
        self._age_days += 1
        self.count_age += 1
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

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age_days

    @staticmethod
    def check_age(age_days: int) -> bool:
        if age_days > 365:
            return True
        return False

    @classmethod
    def create_anonymous(cls) -> "Plant":
        anonymous = Plant("Unknown plant", 0, 0)
        return anonymous

    class Stats:
        def __init__(self, plant: "Plant") -> None:
            self._plant = plant

        def display(self) -> None:
            print(f"[statistics for {self._plant._name}]")
            print(
                f"Stats: {self._plant.count_grow} grow, "
                f"{self._plant.count_age} age, "
                f"{self._plant.count_show} show"
            )

    def bloom(self) -> None:
        if self.asked_grow and self.asked_age:
            print(f"[make {self._name} to grow, age and bloom]")
        elif self.asked_grow:
            print(f"[asking the {self._name} to grow and bloom]")
        else:
            print(f"[asking the {self._name} to bloom]")
        self.bloomed = True
        self.asked_grow = False
        self.asked_age = False


class Flower(Plant):
    def __init__(
            self, name: str,
            color: str, height: float = 0.0, age_days: int = 0) -> None:
        super().__init__(name, height, age_days)
        self.color = color
        self.bloomed = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if not self.bloomed:
            print(f" {self._name} has not bloomed yet")
        else:
            print(f" {self._name} is blooming beautifully!")


class Seed(Flower, Plant):
    def __init__(
            self, name: str,
            color: str, height: float = 0.0, age_days: int = 0,
            seed_count: int = 0) -> None:
        super().__init__(name, color, height, age_days)
        self.seed_count = 0
        if self.bloomed:
            self.seed_count = seed_count

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self.seed_count}")


class Tree(Plant):
    def __init__(
            self, name: str,
            trunk_diameter: float,
            height: float = 0.0, age_days: int = 0) -> None:
        super().__init__(name, height, age_days)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(f"[asking the {self._name} to produce shade]")
        print(
            f"Tree {self._name} now produces a shade of "
            f"{self._height:.1f}cm long and {self.trunk_diameter:.1f}cm wide.")
        self.count_shade += 1

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    class TreeStats(Plant.Stats):
        def __init__(self, tree: "Tree") -> None:
            super().__init__(tree)

        def display(self) -> None:
            super().display()
            print(f" {self._plant.count_shade} shade")


def main() -> None:
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print("Is 30 days more than a year? ->", Plant.check_age(30))
    print("Is 400 days more than a year? ->", Plant.check_age(400))
    print()
    print("=== Flower")
    rose: Flower = Flower("Rose", "red", 15, 10)
    rose.show()
    stats: Plant.Stats = Plant.Stats(rose)
    stats.display()
    rose.grow().bloom()
    rose.show()
    stats.display()

    print()
    print("=== Tree")
    oak: Tree = Tree("Oak", 5, 200, 365)
    oak.show()
    tree_stats: Tree.TreeStats = Tree.TreeStats(oak)
    tree_stats.display()
    oak.produce_shade()
    tree_stats.display()

    print()
    print("=== Seed")
    sunflower: Seed = Seed("Sunflower", "yellow", 80, 45)
    sunflower.show()
    sunflower.age().grow().bloom()
    sunflower.show()
    sunflower_stats: Plant.Stats = Plant.Stats(sunflower)
    sunflower_stats.display()

    print()
    print("=== Anonymous")
    anonymous: Plant = Plant.create_anonymous()
    anonymous.show()
    an_stats: Plant.Stats = Plant.Stats(anonymous)
    an_stats.display()


if __name__ == "__main__":
    main()

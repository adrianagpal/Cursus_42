#!/usr/bin/env python3

class Plant:
    def __init__(
            self, name: str, height: float,
            age_days: int, growth: float) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days
        self.growth = growth

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age_days} days old")

    def grow(self) -> "Plant":
        self.height += self.growth
        return self

    def age(self) -> "Plant":
        self.age_days += 1
        return self


def main() -> None:
    plants: list[Plant] = [
        Plant("Rose", 25, 30, 0.8),
        Plant("Oak", 200, 365, 0.5),
        Plant("Cactus", 5, 90, 1.2),
        Plant("Sunflower", 80, 45, 2.5),
        Plant("Fern", 15, 120, 4.6)
    ]

    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created:", end=" ")
        plant.show()


if __name__ == "__main__":
    main()

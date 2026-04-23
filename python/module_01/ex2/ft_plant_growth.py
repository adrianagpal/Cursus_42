#!/usr/bin/env python3

class Plant:
    def __init__(
            self,
            name: str | None = None,
            height: float = 0.0,
            age_days: int = 0,
            growth: float = 0.0) -> None:
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


def main():
    rose: Plant = Plant()
    rose.name = "Rose"
    rose.height = 25
    rose.age_days = 30
    rose.growth = 0.8
    initial_height: float = rose.height

    print("=== Garden Plant Growth ===")
    rose.show()
    for count in range(1, 8):
        print(f"=== Day {count} ===")
        rose.grow().age().show()
    print(f"Growth this week: {(rose.height - initial_height):.1f}cm")


if __name__ == "__main__":
    main()

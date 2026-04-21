#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = height
        self.age_days = age_days

    def show(self) -> None:
        print(f"{self.name}: {self.height:.1f}cm, {self.age_days} days old")

    def grow(self) -> "Plant":
        self.height += 0.8
        return self

    def age(self) -> "Plant":
        self.age_days += 1
        return self


def main():
    rose: Plant = Plant("Rose", 25, 30)
    initial_height: float = rose.height

    print("=== Garden Plant Growth ===")
    rose.show()
    for count in range(1, 8):
        print(f"=== Day {count} ===")
        rose.grow().age().show()
    print(f"Growth this week: {(rose.height - initial_height):.1f}cm")


if __name__ == "__main__":
    main()

#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float = 0.0, days: int = 0) -> None:
        self._name = name
        if height >= 0:
            self._height = height
        if days >= 0:
            self._days = days

    def show(self) -> None:
        print(f"{self._name}: {self._height:.1f}cm, {self._days} days old")

    def grow(self) -> "Plant":
        self._height += 0.8
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


def main() -> None:
    print("=== Garden Security System ===")
    rose: Plant = Plant("Rose", 15, 10)
    print("Plant created:", end=" ")
    rose.show()
    print()
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    rose.set_age(-5)
    print()
    print("Current state:", end=" ")
    rose.show()


if __name__ == "__main__":
    main()

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

if __name__ == "__main__":
    print("=== Garden Security System ===")
    rose: Plant = Plant("Rose", 15.0, 10)
    print("Plant created:", end = " ")
    rose.show()
    print()
    rose.set_height(25.0)
    rose.set_age(30)
    print()
    rose.set_height(-5)
    rose.set_age(-5)
    print()
    print("Current state:", end = " ")
    rose.show()



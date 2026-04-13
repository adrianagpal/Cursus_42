#!/usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: float, age_days: int):
        self.name = name
        self.height = height
        self.age_days = age_days
    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age_days} days old")
    def grow(self):
        self.height += 0.8
        return self
    def age(self):
        self.age_days += 1
        return self

if __name__ == "__main__":
    plants: list = [
        Plant("Rose", 25.0, 30),
        Plant("Oak", 200.0, 365),
        Plant("Cactus", 5.0, 90),
        Plant("Sunflower", 80, 45),
        Plant("Fern", 15, 120)       
    ]

    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created:", end = " ")
        plant.show()

#!/usr/bin/env python3

class Plant:
    def __init__(
            self,
            name: str | None = None,
            height: float = 0.0,
            age: int = 0) -> None:
        self.name = name
        self.height = height
        self.age = age

    def show(self) -> None:
        print(f"{self.name}: {self.height}cm, {self.age} days old")


def main() -> None:
    rose: Plant = Plant()
    rose.name = "Rose"
    rose.height = 25
    rose.age = 30

    sunflower: Plant = Plant()
    sunflower.name = "Sunflower"
    sunflower.height = 80
    sunflower.age = 45

    cactus: Plant = Plant()
    cactus.name = "Cactus"
    cactus.height = 15
    cactus.age = 120

    print("=== Garden Plant Registry ===")
    rose.show()
    sunflower.show()
    cactus.show()


if __name__ == "__main__":
    main()

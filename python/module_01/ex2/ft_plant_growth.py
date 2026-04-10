class Plant:
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.height = height
        self.age = age
    def show(self) -> None:
        print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")
    def grow_height(self) -> None:
        self.height += 0.8
    def grow_age(self) -> None:
        self.age += 1

    
if __name__ == "__main__":
    rose = Plant("Rose", 25.0, 30)
    initial_height: float = rose.height

    print("=== Garden Plant Growth ===")
    rose.show()
    for count in range(1, 8):
        rose.grow_height()
        rose.grow_age()
        print(f"=== Day {count} ===")  
        rose.show()  
    print(f"Growth this week: {round(rose.height - initial_height, 1)}cm")
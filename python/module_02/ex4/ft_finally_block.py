#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str):
        self.message = message
        super().__init__(self.message)

class PlantError(GardenError):
    def __init__(self):
        message: str = "Invalid plant name to water:"
        super().__init__(message)

def water_plant(plant_name):
    if plant_name != plant_name.capitalize():
        raise PlantError()
    print(f"Watering {plant_name}: [OK]")

def test_watering_system(plant_list: list):
    print("Opening watering system")
    try:
        for plant in plant_list:
            water_plant(plant) 

    except PlantError as pe:
        print(f"Caught PlantError: {pe} {plant_name}")
        print(".. ending tests and returning to main")
    finally:
        print("Closing watering system\n")  

if __name__ == "__main__":
    print("=== Garden Watering System ===\n")
    print("Testing valid plants...")
    valid_plants: list = ["Tomato", "Lettuce", "Carrots"]
    test_watering_system(valid_plants) 

    print("Testing invalid plants...")
    invalid_plants: list = ["Tomato", "lettuce"]
    test_watering_system(invalid_plants)

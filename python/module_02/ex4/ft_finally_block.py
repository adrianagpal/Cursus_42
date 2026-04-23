#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


class PlantError(GardenError):
    def __init__(
            self, plant: str | None = None,
            message: str | None = None) -> None:
        if message is None:
            if plant is None:
                message = "Unknown plant error"
            else:
                message = f"Invalid plant name to water: {plant!r}"
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if plant_name != plant_name.capitalize():
        raise PlantError(plant_name)
    print(f"Watering {plant_name}: [OK]")


def test_watering_system(plant_list: list[str] | None = None) -> None:
    if plant_list is not None:
        print("Opening watering system")
        try:
            for plant in plant_list:
                water_plant(plant)

        except PlantError as pe:
            print(f"Caught PlantError: {pe}")
            print(".. ending tests and returning to main")

        finally:
            print("Closing watering system\n")
            print("Cleanup always happens, even with errors!\n")


def main() -> None:
    print("=== Garden Watering System ===\n")
    print("Testing valid plants...")
    valid_plants: list[str] = ["Tomato", "Lettuce", "Carrots"]
    test_watering_system(valid_plants)

    print("Testing invalid plants...")
    invalid_plants: list[str] = ["Tomato", "lettuce"]
    test_watering_system(invalid_plants)


if __name__ == "__main__":
    main()

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
                message = f"The {plant} plant is wilting!"
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message: str = "Not enough water in the tank!") -> None:
        super().__init__(message)


def raise_plant_error() -> None:
    print("Testing PlantError...")
    try:
        raise PlantError("tomato")
    except PlantError as pe:
        print(f"Caught PlantError: {pe}\n")


def raise_water_error() -> None:
    print("Testing WaterError...")
    try:
        raise WaterError()
    except WaterError as we:
        print(f"Caught WaterError: {we}\n")


def raise_garden_error() -> None:
    print("Testing catching all garden errors...")
    try:
        raise PlantError("tomato")
    except GardenError as ge:
        print(f"Caught GardenError: {ge}")

    try:
        raise WaterError()
    except GardenError as ge:
        print(f"Caught GardenError: {ge}\n")


def main() -> None:
    print("=== Custom Garden Errors Demo ===\n")
    raise_plant_error()
    raise_water_error()
    raise_garden_error()
    print("All custom error types work correctly!")


if __name__ == "__main__":
    main()

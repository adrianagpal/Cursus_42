#!/usr/bin/env python3

class GardenError(Exception):
    def __init__(self, message: str):
        self.message = message
        super().__init__(self.message)

class PlantError(GardenError):
    def __init__(self):
        message: str = "The tomato plant is wilting!"
        super().__init__(message)

class WaterError(GardenError):
    def __init__(self):
        message: str = "Not enough water in the tank!"
        super().__init__(message)

if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===\n")

    print("Testing PlantError...")
    try:
        raise PlantError()
    except PlantError as pe:
        print(f"Caught PlantError: {pe}\n")

    print("Testing WaterError...")
    try:
        raise WaterError()
    except WaterError as we:
        print(f"Caught WaterError: {we}\n")

    print("Testing catching all garden errors...")
    try:
        raise PlantError()
    except GardenError as ge:
        print(f"Caught GardenError: {ge}")

    try:
        raise WaterError()
    except GardenError as ge:
        print(f"Caught GardenError: {ge}\n")

    print("All custom error types work correctly!")





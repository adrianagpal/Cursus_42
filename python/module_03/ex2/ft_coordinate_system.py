#!/usr/bin/env python3

import math

def calculate_euclidean_distance(coord1: list[float], coord2: list[float]) -> float:
    value: float = 0.0
    index: int = 0
    for number in coord1:
        value += (number - coord2[index])**2
        index += 1
    return math.sqrt(value)


def get_player_pos() -> None:
    
    while True:
        raw: str = input("Enter new coordinates as floats in format 'x,y,z': ")
        parts: list[float] = raw.split(",")
        if len(parts) != 3:
            print("Invalid syntax")

        else:
            coord: list[float] = []
            
            try:
                for number in parts:
                    coord += [float(number)]
            except Exception as e:
                print(f"Error on parameter {number}: {e}")

            if len(coord) == 3:   
                (x, y, z) = coord
                print(f"Got a first tuple: {(x, y, z)}")
                print(f"It includes: X={x}, Y={y}, Z={z}")
                return (x, y, z)

def main() -> None:
    print("=== Game Coordinate System ===\n")
    print("Get a first set of coordinates")
    (x1, y1, z1) = get_player_pos()

    print("Get a second set of coordinates")
    (x2, y2, z2) = get_player_pos()
    
    print(f"Distance to center: {calculate_euclidean_distance(coord):.4f}\n")


if __name__ == "__main__":
    main()

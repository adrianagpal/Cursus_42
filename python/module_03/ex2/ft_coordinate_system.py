#!/usr/bin/env python3

import math


def get_euclidean_distance(
        coord1: tuple[float], coord2: tuple[float]) -> float:
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
                return (x, y, z)


def main() -> None:
    print("=== Game Coordinate System ===\n")
    
    print("Get a first set of coordinates")
    (x1, y1, z1) = get_player_pos()
    print(f"Got a first tuple: {(x1, y1, z1)}")
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")
    dist_to_center: float = get_euclidean_distance((x1, y1, z1), (0, 0, 0))
    print(f"Distance to center: {dist_to_center:.4f}\n")

    print("Get a second set of coordinates")
    dist_coord: float = get_euclidean_distance((x1, y1, z1), get_player_pos())
    print(f"Distance between the 2 sets of coordinates: {dist_coord:.4f}\n")


if __name__ == "__main__":
    main()

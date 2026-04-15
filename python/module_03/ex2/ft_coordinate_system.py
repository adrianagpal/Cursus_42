#!/usr/bin/env python3

import math

def get_player_pos():
    coord = (input("Enter new coordinates as floats in format 'x,y,z':"))

    print(f"Got a first tuple: {coord}")
    print(f"It includes: X={coord[0]}, Y={coord[1]}, Z={coord[2]}")

if __name__ == "__main__":
    get_player_pos()
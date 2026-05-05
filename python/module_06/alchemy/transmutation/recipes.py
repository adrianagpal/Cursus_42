#!/usr/bin/env python3

import alchemy
import elements

def lead_to_gold():
    return (f"Recipe transmuting Lead to Gold: brew "
            f"{alchemy.create_air()!r} and {alchemy.strength_potion()!r} "
            f"mixed with {elements.create_fire()!r}")
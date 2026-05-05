#!/usr/bin/env python3

from .elements import create_air, create_earth
import elements

def healing_potion():
    return  (f"Healing potion brewed with {create_earth()!r} "
             f"and {create_air()!r}")


def  strength_potion():
    return  (f"Strength potion brewed with {elements.create_fire()!r} "
             f"and {elements.create_water()!r}")
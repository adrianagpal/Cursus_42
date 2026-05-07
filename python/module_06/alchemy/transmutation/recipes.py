from ..elements import create_air
from ..potions import strength_potion
import elements


def lead_to_gold() -> str:
    return (f"Recipe transmuting Lead to Gold: brew "
            f"{create_air()!r} and {strength_potion()!r} "
            f"mixed with {elements.create_fire()!r}")

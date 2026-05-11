#!/usr/bin/env python3

from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex0.creature import Creature
from typing import TypeVar


BaseT = TypeVar("BaseT", bound=Creature)
EvolvedT = TypeVar("EvolvedT", bound=Creature)


def verify_factory(factory: CreatureFactory[BaseT, EvolvedT]) -> None:

    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())

    evolution = factory.create_evolved()
    print(evolution.describe())
    print(evolution.attack())
    print()


def main() -> None:

    flame_factory = FlameFactory()
    verify_factory(flame_factory)

    aqua_factory = AquaFactory()
    verify_factory(aqua_factory)

    print("Testing battle")
    flameling = flame_factory.create_base()
    print(flameling.describe())
    print(" vs.")
    aquabub = aqua_factory.create_base()
    print(aquabub.describe())
    print(" fight!")
    print(flameling.attack())
    print(aquabub.attack())


if __name__ == "__main__":
    main()

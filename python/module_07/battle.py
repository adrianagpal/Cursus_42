#!/usr/bin/env python3

from ex0 import CreatureFactory, FlameFactory, AquaFactory


def verify_factory(factory: CreatureFactory) -> None:

    print("Testing factory")
    base = factory.create_base()
    print(base.describe())
    print(base.attack())

    evolution = factory.create_evolved()
    print(evolution.describe())
    print(evolution.attack())


def creature_battle(factory1: CreatureFactory,
                    factory2: CreatureFactory) -> None:

    print("Testing battle")
    base1 = factory1.create_base()
    print(base1.describe())
    print(" vs.")
    base2 = factory2.create_base()
    print(base2.describe())
    print(" fight!")
    print(base1.attack())
    print(base2.attack())


def main() -> None:

    flame_factory = FlameFactory()
    verify_factory(flame_factory)
    print()

    aqua_factory = AquaFactory()
    verify_factory(aqua_factory)
    print()

    creature_battle(flame_factory, aqua_factory)


if __name__ == "__main__":
    main()

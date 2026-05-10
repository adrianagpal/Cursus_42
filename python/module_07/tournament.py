#!/usr/bin/env python3

from ex0.creature import Creature
from ex0 import FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleStrategy
from ex2 import NormalStrategy, DefensiveStrategy, AggressiveStrategy
import random


def battle(opponents: list[tuple[Creature, BattleStrategy]]) -> None:

    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved\n")

    for index1 in range(len(opponents)):
        for index2 in range(index1 + 1, len(opponents)):

            creature1, strategy1 = opponents[index1]
            creature2, strategy2 = opponents[index2]

            print("* Battle *")
            print(creature1.describe())
            print(" vs.")
            print(creature2.describe())
            print(" now fight!")

            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
                print()
            except Exception as e:
                print(f"Battle error, aborting tournament: {e}\n")


def main() -> None:

    heal_factory: HealingCreatureFactory = HealingCreatureFactory()
    transform_factory: TransformCreatureFactory = TransformCreatureFactory()

    heal_creatures: list[Creature] = [heal_factory.create_base(),
                                      heal_factory.create_evolved()]

    trans_creatures: list[Creature] = [transform_factory.create_base(),
                                       transform_factory.create_evolved()]

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    flame_factory = FlameFactory()
    flameling = flame_factory.create_base()
    tournament0 = [
        (flameling, NormalStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy())
    ]
    battle(tournament0)

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")

    tournament1 = [
        (flameling, AggressiveStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy())
    ]
    battle(tournament1)

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")

    aqua_factory = AquaFactory()
    aquabub = aqua_factory.create_base()
    tournament2 = [
        (aquabub, NormalStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy()),
        (random.choice(trans_creatures), AggressiveStrategy())
    ]
    battle(tournament2)


if __name__ == '__main__':
    main()

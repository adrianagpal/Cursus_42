#!/usr/bin/env python3

from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex2 import BattleStrategy
from ex2 import NormalStrategy, DefensiveStrategy, AggressiveStrategy
from typing import Any, TypeAlias
import random


def battle(opponents: list[tuple[CreatureFactory[Any, Any],
                                 BattleStrategy[Any]]]) -> None:

    methods = ["create_base", "create_evolved"]

    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved\n")

    for index1 in range(len(opponents)):
        for index2 in range(index1 + 1, len(opponents)):

            factory1, strategy1 = opponents[index1]
            factory2, strategy2 = opponents[index2]
            creature1 = getattr(factory1, random.choice(methods))()
            creature2 = getattr(factory2, random.choice(methods))()

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

    heal_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    normal: BattleStrategy[Any] = NormalStrategy()
    defensive: BattleStrategy[Any] = DefensiveStrategy()
    aggressive: BattleStrategy[Any] = AggressiveStrategy()

    factories: list[CreatureFactory[Any, Any]] = [heal_factory,
                                                  transform_factory]

    Opponent: TypeAlias = tuple[
        CreatureFactory[Any, Any],
        BattleStrategy[Any],
    ]

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    tournament0: list[Opponent] = [
        (FlameFactory(), normal),
        (random.choice(factories), defensive)
    ]
    battle(tournament0)

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")

    tournament1: list[Opponent] = [
        (FlameFactory(), aggressive),
        (random.choice(factories), defensive)
    ]
    battle(tournament1)

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")

    tournament2: list[Opponent] = [
        (AquaFactory(), normal),
        (random.choice(factories), defensive),
        (random.choice(factories), aggressive)
    ]
    battle(tournament2)


if __name__ == '__main__':
    main()

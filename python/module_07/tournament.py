
from ex0.creature import Creature, Flameling, Aquabub
from ex1.capability import Sproutling, Bloomelle, Shiftling, Morphagon
from ex2 import BattleStrategy, NormalStrategy, DefensiveStrategy, AggressiveStrategy
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
            print(" fight!")

            try:
                strategy1.act(creature1)
                strategy2.act(creature2)
                print()
            except Exception as e:
                print(f"Battle error, aborting tournament: {e}")


def main() -> None:

    heal_creatures: list[Creature] = [Sproutling(), Bloomelle()]
    trans_creatures: list[Creature] = [Shiftling(), Morphagon()]

    print("Tournament 0 (basic)")
    print(" [ (Flameling+Normal), (Healing+Defensive) ]")

    tournament0 = [
        (Flameling(), NormalStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy())
    ]
    battle(tournament0)

    print("Tournament 1 (error)")
    print(" [ (Flameling+Aggressive), (Healing+Defensive) ]")

    tournament1 = [
        (Flameling(), AggressiveStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy())
    ]
    battle(tournament1)

    print("Tournament 2 (multiple)")
    print(" [ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]")

    tournament2 = [
        (Aquabub(), NormalStrategy()),
        (random.choice(heal_creatures), DefensiveStrategy()),
        (random.choice(trans_creatures), AggressiveStrategy())
    ]
    battle(tournament2)


if __name__ == '__main__':
    main()

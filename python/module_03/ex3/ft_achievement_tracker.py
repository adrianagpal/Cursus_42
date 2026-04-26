#!/usr/bin/env python3

import random


# Transform set into list because random.sample is deprecated with sets
def gen_player_achievements(achievements: list[str]) -> set[str]:
    k: int = random.randint(1, len(achievements))
    return set(random.sample(achievements, k))


def main() -> None:
    print("=== Achievement Tracker System ===\n")

    achievements = [
        'Crafting Genius', 'Strategist', 'World Savior',
        'Speed Runner', 'Survivor', 'Master Explorer',
        'Treasure Hunter', 'Unstoppable', 'First Steps',
        'Collector Supreme', 'Untouchable', 'Sharp Mind',
        'Boss Slayer'
    ]

    players: list[str] = ["alice", "bob", "charlie", "dylan"]
    achievement_dict: dict[str, set[str]] = {}

    for player in players:
        achievement_dict[player] = gen_player_achievements(achievements)
        print(f"Player {player.capitalize()}: {achievement_dict[player]}")
    print()

    print(f"All distinct achievements: {set(achievements)}\n")

    print("Common achievements: "
          f"{set.intersection(*(achievement_dict[x] for x in players))}\n")

    for player in players:
        others_sets = (achievement_dict[x] for x in players if x != player)
        union_set: set[str] = set.union(*others_sets)
        print(f"Only {player.capitalize()} has: "
              f"{set.difference(achievement_dict[player], union_set)}")
    print()

    for player in players:
        print(f"{player.capitalize()} is missing: "
              f"{set.difference(set(achievements), achievement_dict[player])}")
    print()


if __name__ == "__main__":
    main()

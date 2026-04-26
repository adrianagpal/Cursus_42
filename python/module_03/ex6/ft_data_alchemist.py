#!/usr/bin/env python3

import random


def main() -> None:
    print("=== Game Data Alchemist ===\n")

    initial_players: list[str] = [
        'Alice', 'bob', 'Charlie', 'dylan', 'Emma',
        'Gregory', 'john', 'kevin', 'Liam'
    ]
    new_list: list[str] = [x.capitalize() for x in initial_players]
    cap_list: list[str] = [x for x in initial_players if x == x.capitalize()]

    print(f"Initial list of players: {initial_players}")
    print(f"New list with all names capitalized: {new_list}")
    print(f"New list of capitalized names only: {cap_list}\n")

    score_dict: dict[str, int] = {x: random.randint(0, 1000) for x in new_list}
    sum_scores: float = sum([score_dict[key] for key in score_dict])
    avg_score: float = sum_scores/len(score_dict)

    high_scores: dict[str, int] = {key: score_dict[key] for key in score_dict
                                   if score_dict[key] > avg_score}

    print(f"Score dict: {score_dict}")
    print(f"Score average is {avg_score:.2f}")
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()

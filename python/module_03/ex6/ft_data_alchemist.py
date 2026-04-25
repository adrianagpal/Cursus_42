#!/usr/bin/env python3

import random


def main() -> None:
    print("=== Game Data Alchemist ===\n")

    initial_players: list[str] = ['Alice', 'bob', 'Charlie', 'dylan', 'Emma', 'Gregory', 'john', 'kevin', 'Liam']

    print(f"Initial list of players: {initial_players}")

    new_list: list[str] = [x.capitalize() for x in initial_players]

    print(f"New list with all names capitalized: {new_list}")

    capitalized_list: list[str] = [x for x in initial_players if x == x.capitalize()]

    print(f"New list of capitalized names only: {capitalized_list}\n")

    score_dict: dict = {x: random.randint(0, 1000) for x in new_list}

    print(f"Score dict: {score_dict}")

    sum_scores: float = sum([score_dict[key] for key in score_dict])
    avg_score: float = sum_scores/len(score_dict)

    print(f"Score average is {avg_score:.2f}")

    high_scores: dict = {key: score_dict[key] for key in score_dict if score_dict[key] > avg_score}

    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    main()

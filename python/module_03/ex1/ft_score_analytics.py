#!/usr/bin/env python3

import sys


def create_new_list(arg_list: list[str]) -> list[int]:
    new_list: list[int] = []
    for arg in arg_list:
        try:
            new_list += [int(arg)]

        except ValueError:
            print(f"Invalid parameter: {arg!r}")

    return new_list


def main() -> None:
    print("=== Player Score Analytics ===")

    arg_list: list[int] = create_new_list(sys.argv[1:])
    n_arg: int = len(arg_list)

    if not arg_list:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...\n")

    else:
        print(f"Scores processed: {arg_list}")
        print(f"Total players: {n_arg}")
        print(f"Total score: {sum(arg_list)}")
        print(f"Average score: {sum(arg_list)/n_arg}")
        print(f"High score: {max(arg_list)}")
        print(f"Low score: {min(arg_list)}")
        print(f"Score range: {max(arg_list) - min(arg_list)}\n")


if __name__ == "__main__":
    main()

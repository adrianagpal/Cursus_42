#!/usr/bin/env python3

import sys

if __name__ == "__main__":
    print("=== Player Score Analytics ===")

    n_arg: int = len(sys.argv)
    index: int = 1
    arg_list: list = []

    try:
        for arg in sys.argv:
            arg_list += [int(arg)]

    except Exception as te:
        print(f"Invalid parameter: {arg}")
        print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ..")

    finally:     
        print(f"Total players: {len(arg_list)}")
        print(f"Total score: {sum(arg_list)}")
        print(f"Average score: {sum(arg_list)/len(arg_list)}")
        print(f"High score: {max(arg_list)}")
        print(f"Low score: {min(arg_list)}")
        print(f"Score range: {max(arg_list) - min(arg_list)}")
        print(arg_list)

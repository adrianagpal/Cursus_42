#!/usr/bin/env python3

import random


achievements = ['Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner', 'Survivor',
'Master Explorer', 'Treasure Hunter', 'Unstoppable', 'First Steps', 'Collector Supreme', 'Untouchable', 'Sharp Mind', 'Boss Slayer']

# Transform set into list because random.sample is deprecated with sets
def gen_player_achievements():
    new_set = set(random.sample(achievements, k=6))

    return new_set


def main() -> None:
    alice: set = gen_player_achievements()
    bob: set = gen_player_achievements()
    charlie: set = gen_player_achievements()
    dylan: set = gen_player_achievements()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}\n")

    print(f"All distinct achievements: {set(achievements)}\n")

    print(f"Common achievements: {set.intersection(alice, bob, charlie, dylan)}\n")

    print(f"Only Alice has: {set.difference(alice, set.union(bob, charlie, dylan))}")
    print(f"Only Bob has: {set.difference(bob, set.union(alice, charlie, dylan))}")
    print(f"Only Charlie has: {set.difference(charlie, set.union(bob, alice, dylan))}")
    print(f"Only Dylan has: {set.difference(dylan, set.union(bob, charlie, alice))}\n")

    print(f"Alice is missing: {set.difference(set(achievements), alice)}")
    print(f"Bob is missing: {set.difference(set(achievements), bob)}")
    print(f"Charlie is missing: {set.difference(set(achievements), charlie)}")
    print(f"Dylan is missing: {set.difference(set(achievements), dylan)}")


    

main()
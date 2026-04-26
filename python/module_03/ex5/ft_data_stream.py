#!/usr/bin/env python3

import random
import typing


def gen_event() -> typing.Generator[tuple, None, None]:
    players: list[str] = ["bob", "alice", "dylan", "charlie"]
    actions: list[str] = [
        "run", "eat", "sleep", "grab", "move", "climb", "swim", "release"
    ]

    while True:
        name: str = random.choice(players)
        action: str = random.choice(actions)
        yield (name, action)


def consume_event(
    list_events: list[tuple[str, str]]) -> typing.Generator[
        tuple[tuple[str, str], list[tuple[str, str]]], None, None]:

    while list_events:
        index: int = random.randrange(0, len(list_events))
        event: tuple[str, str] = list_events[index]
        length: int = len(list_events)
        list_events = [list_events[x] for x in range(length) if x != index]
        yield event, list_events


def main() -> None:
    print("=== Game Data Stream Processor ===")
    gen = gen_event()
    list_events: list[tuple[str, str]] = []

    for _ in range(0, 1000):
        name, action = next(gen)
        print(f"Event {_}: Player {name} did action {action}")

    for _ in range(0, 10):
        name, action = next(gen)
        list_events += [(name, action)]

    print(f"Built list of 10 events: {list_events}")

    consume_gen = consume_event(list_events)

    for _ in range(0, len(list_events)):
        event, list_events = next(consume_gen)
        print(f"Got event from list: {event}")
        print(f"Remains in list: {list_events}")


if __name__ == "__main__":
    main()

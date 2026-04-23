#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is {temp_str!r}")

    return int(temp_str)


def test_temperature() -> None:
    inputs: list = ["25", "abc"]
    for input in inputs:
        try:
            input_temperature(input)
            print(f"Temperature is now {input}°C\n")

        except ValueError as ve:
            print(f"Caught input_temperature error: {ve}\n")

    print("All tests completed - program didn't crash!")


def main() -> None:
    print("=== Garden Temperature ===\n")

    test_temperature()


if __name__ == "__main__":
    main()

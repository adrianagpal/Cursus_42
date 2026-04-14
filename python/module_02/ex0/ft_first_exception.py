#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is {temp_str!r}")
    
    temp: int = test_temperature(temp_str)

    if temp != None:
        print(f"Temperature is now {temp}°C\n")
        return temp

def test_temperature(temp_str) -> int:
    try:
        temp: int = int(temp_str)
        return temp

    except ValueError as e:
        print(f"Caught input_temperature error: {e}\n")

if __name__ == "__main__":
    print("=== Garden Temperature ===\n")

    temp_str: str = '25'
    input_temperature(temp_str)

    # It doesnt print the apostrophe
    abc_str: str = 'abc'
    input_temperature(abc_str)

    print("All tests completed - program didn't crash!")

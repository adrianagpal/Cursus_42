#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is {temp_str!r}")
    
    temp: int = int(temp_str)

    if temp < 0:
        raise Exception(f"Caught input_temperature error: {temp}°C is too cold for plants (min 0°C)\n")
             
    elif temp > 40:
        raise Exception(f"Caught input_temperature error: {temp}°C is too hot for plants (max 40°C)\n")

    print(f"Temperature is now {temp}°C\n")
    return temp

def test_temperature(temp_str: str) -> None:
    try:
        input_temperature(temp_str)

    except ValueError as err:
        print(f"Caught input_temperature error: {err}\n")

    except Exception as exc:
        print(exc)

if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")

    test_temperature('25')

    # It doesnt print the apostrophe
    test_temperature('abc')

    test_temperature('100')

    test_temperature('-50')

    print("All tests completed - program didn't crash!")
#!/usr/bin/env python3

def input_temperature(temp_str: str) -> int:
    print(f"Input data is {temp_str!r}")
    
    temp: int = int(temp_str)

    if temp < 0:
        raise Exception(f"Caught input_temperature error: {temp}°C is too cold for plants (min 0°C)\n")
             
    elif temp > 40:
        raise Exception(f"Caught input_temperature error: {temp}°C is too hot for plants (max 40°C)\n")

    return temp

def test_temperature() -> None:
    inputs: list = ["25", "abc", "100", "-50"]
    for input in inputs: 
        try:
            input_temperature(input)
            print(f"Temperature is now {input}°C\n")

        except ValueError as err:
            print(f"Caught input_temperature error: {err}\n")

        except Exception as exc:
            print(exc)

    print("All tests completed - program didn't crash!")

if __name__ == "__main__":
    print("=== Garden Temperature Checker ===\n")

    test_temperature()
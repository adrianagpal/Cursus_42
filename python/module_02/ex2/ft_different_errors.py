#!/usr/bin/env python3

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        temp: int = int('abc')
    elif operation_number == 1:
        div: int = 5/0
    elif operation_number == 2:
        open('/non/existent/file', 'r')
    elif operation_number == 3:
        'abc' + 5
    return

def test_error_types() -> None:
    inputs:  list = [0, 1, 2, 3]
    for input in inputs: 
        try:
            print(f"Testing operation {operation}...")
            garden_operations(operation)
        except ValueError as ve:
            print(f"Caught ValueError: {ve}")
        except ZeroDivisionError as zde:
            print(f"Caught ZeroDivisionError: {zde}")
        except FileNotFoundError as fne:
            print(f"Caught FileNotFoundError: {fne}")
        except TypeError as te:
            print(f"Caught TypeError: {te}")
        else:
            print("Operation completed successfully\n")

if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    index: int = 0
    while index < 5:
        test_error_types(index)
        index += 1

    print("All error types tested successfully!")
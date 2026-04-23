#!/usr/bin/env python3

def garden_operations(operation_number: int) -> None:
    if operation_number == 0:
        int('abc')
    elif operation_number == 1:
        5/0
    elif operation_number == 2:
        open('/non/existent/file', 'r')
    elif operation_number == 3:
        'abc' + 5
    return


def test_error_types() -> None:
    inputs: list[int] = [0, 1, 2, 3, 4]
    for input in inputs:
        try:
            print(f"Testing operation {input}...")
            garden_operations(input)
        except Exception as e:
            print(f"Caught {e.__class__.__name__}: {e}")

    print("Operation completed successfully\n")
    print("All error types tested successfully!")


def main() -> None:
    print("=== Garden Error Types Demo ===")

    test_error_types()


if __name__ == "__main__":
    main()

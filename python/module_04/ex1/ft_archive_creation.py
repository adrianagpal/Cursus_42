#!/usr/bin/env python3

import sys
import typing


def transform_data(content: str) -> None:
    print("Transform data:",
          "---\n", content, "\n---", sep="\n")

    file_name: str = input("Enter new file name (or empty): ")

    if file_name:
        print(f"Saving data to {file_name!r}\n"
              f"Data saved in file {file_name!r}.\n")
        try:
            a: typing.IO = open(file_name, "w")
            a.write(content)
            if a is not None:
                a.close()
        except Exception as e:
            print(f"Error opening file {file_name!r}: {e}\n"
                  "Not saving data.")
    else:
        print("Not saving data.\n")


def main() -> None:
    n_arg: int = len(sys.argv)
    f: typing.IO | None = None

    if n_arg != 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file {sys.argv[1]!r}")
        file_contents: str = ""
        try:
            f = open(sys.argv[1])
            file_contents = f.read()
            print("---\n", file_contents, "\n---", sep="\n")
        except Exception as e:
            print(f"Error opening file {sys.argv[1]!r}: {e}\n")
        finally:
            if f is not None:
                f.close()

                print(f"File {sys.argv[1]!r} closed.\n")
                new_contents: str = file_contents.replace("\n", "#\n")

                if not file_contents.endswith("\n"):
                    new_contents += "#"

                transform_data(new_contents)


if __name__ == "__main__":
    main()

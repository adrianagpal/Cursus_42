#!/usr/bin/env python3

import sys
import typing


def main() -> None:
    n_arg: int = len(sys.argv)
    f: typing.IO | None = None

    if n_arg != 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file {sys.argv[1]!r}")
        file_contents: str = ""
        try:
            f = open(sys.argv[1])
            file_contents = f.read()
            print("---\n", file_contents, "---", sep="\n")
        except Exception as e:
            print(f"Error opening file {sys.argv[1]!r}: {e}\n")
        finally:
            if f is not None:
                f.close()
                print(f"File {sys.argv[1]!r} closed.")


if __name__ == "__main__":
    main()

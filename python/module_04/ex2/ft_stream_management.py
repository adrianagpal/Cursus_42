#!/usr/bin/env python3

import sys
import typing


def transform_data(content: str) -> None:
    sys.stdout.write(f"Transform data:\n---\n\n{content}\n---\n"
                     "Enter new file name (or empty): ")
    sys.stdout.flush()
    file_name: str = ""

    try:
        file_name = sys.stdin.readline().rstrip("\n")
    except KeyboardInterrupt:
        sys.stderr.write("\nProgram interrumpted\n")

    if file_name:
        sys.stdout.write(f"Saving data to {file_name!r}\n")
        try:
            a: typing.IO = open(file_name, "w")
            a.write(content)
            if a is not None:
                a.close()
            sys.stdout.write(f"Data saved in file {file_name!r}.\n")
        except Exception as e:
            sys.stderr.write(f"[STDERR] Error opening file "
                             f"{sys.argv[1]!r}: {e}\n"
                             "Data not saved.\n")
    else:
        sys.stdout.write("Data not saved.")
        sys.stdout.flush()


def main() -> None:
    n_arg: int = len(sys.argv)
    f: typing.IO | None = None

    if n_arg != 2:
        sys.stdout.write(f"Usage: {sys.argv[0]} <file>\n\n")
    else:
        file_contents: str = ""
        sys.stdout.write("=== Cyber Archives Recovery & Preservation ===\n"
                         f"Accessing file {sys.argv[1]!r}\n")
        sys.stdout.flush()

        try:
            f = open(sys.argv[1])
            file_contents = f.read()
            sys.stdout.write(f"---\n\n{file_contents}\n---\n")

        except Exception as e:
            sys.stderr.write(f"[STDERR] Error opening file "
                             f"{sys.argv[1]!r}: {e}\n")
        finally:
            if f is not None:
                f.close()
                if f.closed:
                    sys.stdout.write(f"File {sys.argv[1]!r} closed.\n\n")

                new_contents: str = file_contents.replace("\n", "#\n")
                if not file_contents.endswith("\n"):
                    new_contents += "#"

                transform_data(new_contents)


if __name__ == "__main__":
    main()

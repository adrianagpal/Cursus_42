#!/usr/bin/env python3

import sys, typing


#def transform_data():



def main() -> None:
    n_arg: int = len(sys.argv)
    f: typing.IO | None = None

    if n_arg != 2:
        print(f"Usage: {sys.argv[0]} <file>\n")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file {sys.argv[1]!r}")
        try:
            f = open(sys.argv[1])
            file_contents: str = f.read()
            print("---\n", file_contents, "\n---", sep = "\n")
        except FileNotFoundError as fe:
            print(f"Error opening file {sys.argv[1]!r}: {fe}\n")
        except PermissionError as pe:
            print(f"Error opening file {sys.argv[1]!r}: {pe}\n")
        finally:
            if f is not None:                
                print(f"File {sys.argv[1]!r} closed.\n")
                new_contents = file_contents.replace("\n", "#\n")
                if not file_contents.endswith("\n"):
                    new_contents += "#"
                print("Transform data:", "---\n", new_contents, "\n---", sep = "\n")   

                print("Enter new file name (or empty): ", end="", flush=True)             

                file_name = sys.stdin.read()
                
                if file_name:
                    print(f"Saving data to {file_name!r}\n"
                          f"Data saved in file {file_name!r}.\n")
                    a: typing.IO = open(file_name, "w")
                    a.write(new_contents)
                    a.close()

                else:
                    print("Not saving data.")

                f.close()


if __name__ == "__main__":
    main()

#!/usr/bin/env python3


def secure_archive(
        file_name: str,
        action: str | None = "read", content: str = "") -> tuple[bool, str]:

    success: bool = False
    try:
        with open(file_name) as f:
            success = True
            file_contents: str = f.read()

            if action == "write":
                with open('new_file.txt', "w+") as new_file:
                    new_file.write(content)
                return (success, 'Content successfully written to file')

            return (success, file_contents)

    except Exception as e:
        return (success, f"{e}")


def main() -> None:
    print("=== Cyber Archives Security ===", '\n')

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive('/not/existing/file'), '\n')

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive('/home/adrianag/etc/master.passwd'), '\n')

    print("Using 'secure_archive' to read from a regular file:")
    print(secure_archive('../ex0/ancient_fragment.txt'), '\n')

    print("Using 'secure_archive' to write previous content to a new file:")
    print(secure_archive('../ex0/ancient_fragment.txt', "write"), '\n')


if __name__ == "__main__":
    main()

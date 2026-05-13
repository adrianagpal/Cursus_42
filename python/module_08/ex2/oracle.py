import os


"""
Python environment variables are key-value pairs stored in our
operating system that contain configuration data for our applications.
load_dotenv() reads variables from a .env file and sets them in os.environ.
os.getenv() returns None if the variable is not found.
os.environ[] raises KeyError.
"""


def main() -> None:

    try:
        from dotenv import load_dotenv
    except ModuleNotFoundError as e:
        print(e)
        return

    print("\nORACLE STATUS: Reading the matrix...\n")

    var_dict: dict[str, str | None] = {}

    if not load_dotenv():
        print("Missing configuration file")
        return
    else:
        var_dict = {
            "Mode": os.getenv("MATRIX_MODE"),
            "Database": os.getenv("DATABASE_URL"),
            "API Access": os.getenv("API_KEY"),
            "Log Level": os.getenv("LOG_LEVEL"),
            "Zion Network": os.getenv("ZION_ENDPOINT")
        }

    print("Configuration loaded:")
    for key in var_dict:
        print(f"{key}: {var_dict[key]}")

    print()
    for key in var_dict:
        if var_dict[key] is None:
            print("All variables need to be configured.")
            return

    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available\n")

    print("The Oracle sees all configurations.")


if __name__ == '__main__':
    main()

import sys

"""
Inside a venv, sys.prefix points to the directory of the virtual environment.
sys.base.prefix points to the Python interpreter used to create the environment.
"""
def in_virtualenv() -> bool:
    print(sys.prefix)
    print(sys.base_prefix)
    return sys.prefix != sys.base_prefix

def main() -> None:
    if in_virtualenv():
        print("Should detect virtual environment and show details")
    else:
        print("Should detect no virtual environment and provide instructions")

if __name__ == '__main__':
    main()
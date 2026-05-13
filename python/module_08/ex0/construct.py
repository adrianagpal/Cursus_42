#!/usr/bin/env python3

import sys
import os
import site

"""
sys.prefix points to the directory of the Python installation. If in a venv,
this will point out to the directory of the virtual environment.
sys.base.prefix points to the Python interpreter of the base installation.
"""


def in_virtualenv() -> bool:

    return sys.prefix != sys.base_prefix


def output_base(venv: str) -> None:

    print("\nMATRIX STATUS: You're still plugged in\n")

    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {venv}\n")

    print("WARNING: You're in the global environment!\n"
          "The machines can see everything you install.\n")

    print("To enter the construct, run:\n"
          "python -m venv matrix_env\n"
          "source matrix_env/bin/activate # On Unix\n"
          "matrix_env\\Scripts\\activate # On Windows\n")
    print("Then run this program again.")


def output_venv(venv: str) -> None:

    print("\nMATRIX STATUS: Welcome to the construct\n")

    print(f"Current Python: {sys.executable}")
    print(f"Virtual Environment: {venv}")
    print(f"Environment Path: {sys.prefix}\n")

    print("SUCCESS: You're in an isolated environment!\n"
          "Safe to install packages without affecting\n"
          "the global system.\n")
    print("Package installation path:")
    print(site.getsitepackages()[0])


def main() -> None:

    venv: str = (
        os.path.basename(sys.prefix)
        if in_virtualenv()
        else "None detected"
    )

    if in_virtualenv():
        output_venv(venv)
    else:
        output_base(venv)


if __name__ == '__main__':
    main()

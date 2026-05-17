from functools import wraps
import time
from typing import Callable

class MageGuild:

    @staticmethod
    def validate_mage_name(name: str) -> bool:

        return len(name) > 2 and all((char.isspace() | char.isalpha()) for char in name)

    def cast_spell(self, spell_name: str, power: int) -> str:
        pass


def spell_timer(func: Callable) -> Callable:

    @wraps(func)
    def wrapper():
        print(f"Casting {func.__name__}...")
        begin = time.time()
        result = func()
        end = time.time()

        print(f"Spell completed in {(end-begin):.3f} seconds")
        return result
    
    return wrapper


@spell_timer
def fireball() -> str:
    time.sleep(0.101)
    return "Fireball cast!"


def main() -> None:
    print("Testing spell timer...")
    print('Result: ', fireball())


if __name__ == '__main__':
    main()





def power_validator(min_power: int) -> Callable:

    def wrapper():
        

#def retry_spell(max_attempts: int) -> Callable




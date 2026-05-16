from functools import reduce, partial, lru_cache, singledispatch
import operator
from typing import Callable, Any
import time


"""
reduce() function (from the functools module) applies a function cumulatively 
to the elements of an iterable and returns a single final value. It processes 
elements step-by-step, combining two elements at a time until only one result remains.
"""


def spell_reducer(spells: list[int], operation: str) -> int:

    operator_dict = {
        "add": operator.add, 
        "multiply": operator.mul, 
        "max": max, 
        "min": min
    }

    if not spells:
        return 0

    if operation in operator_dict:            
        return reduce(operator_dict[operation], spells)
        
    return -1


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:

    def partial(base_enchantment, *args, **keywords):
        ...


@lru_cache
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    
    return memoized_fibonacci(n-1) + memoized_fibonacci(n-2)


def fibonacci_no_cache(n: int) -> int:
    if n < 2:
        return n
    
    return fibonacci_no_cache(n-1) + fibonacci_no_cache(n-2)


@singledispatch
def spell_dispatcher(type: Any) -> Callable[[Any], str]:




def main() -> None:

    print("Testing spell reducer...")
    spells = [2, 5, 6, 3, 8]

    print(f"Sum: {spell_reducer(spells, 'add')}")
    print(f"Product: {spell_reducer(spells, 'multiply')}")
    print(f"Max: {spell_reducer(spells, 'max')}")

    print()
    print("Testing memoized fibonacci...")
    print(f"Fib(0): {memoized_fibonacci(0)}")
    print(f"Fib(1): {memoized_fibonacci(1)}")
    print(f"Fib(10): {memoized_fibonacci(10)}")
    print(f"Fib(15): {memoized_fibonacci(15)}")

    begin = time.time()
    memoized_fibonacci(30)
    end = time.time()
    print("Time taken to execute the "
          f"function with lru_cache is", end-begin)
    
    begin = time.time()
    fibonacci_no_cache(30)
    end = time.time()
    print("Time taken to execute the "
          f"function without lru_cache is", end-begin)





if __name__ == '__main__':
    main()

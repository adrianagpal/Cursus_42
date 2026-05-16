from typing import Callable

# https://www.geeksforgeeks.org/python/python-closures/

def mage_counter(mage) -> Callable:
    count = 0

    def counter():
        nonlocal count
        count += 1
        return count
    
    return counter


def spell_accumulator(initial_power: int) -> Callable:

    power = initial_power

    def accumulator(amount: int):
        nonlocal power
        power += amount

        return power

    return accumulator


def enchantment_factory(enchantment_type: str) -> Callable:

    def apply_enchanment(item_name):

        return " ".join([enchantment_type, item_name])
    
    return apply_enchanment


def memory_vault() -> dict[str, Callable]:

    memory_dict = {}

    def store(key, value):
        memory_dict[key] = value

        def recall(key):
            try:
                return memory_dict[key]
            except:
                return "Memory not found"
            
        return recall
        
    return store



def main() -> None:

    print("Testing mage counter...")
    counter_a = mage_counter("counter_a")
    counter_b = mage_counter("counter_b")

    for i in range(2):
        print(f"counter_a call {i + 1}: {counter_a()}")

    for j in range(1):
        print(f"counter_b call {j + 1}: {counter_b()}")

    print()
    print("Testing spell accumulator...")
    initial_power = 100
    spell_acc = spell_accumulator(initial_power)
    print(f"Base {initial_power}, add 20: {spell_acc(20)}")
    print(f"Base {initial_power}, add 30: {spell_acc(30)}")

    print()
    print("Testing enchantment factory...")
    flaming_func = enchantment_factory("Flaming")
    flaming_sword = flaming_func("Sword")
    print(flaming_sword)

    frozen_func = enchantment_factory("Frozen")
    frozen_shield = frozen_func("Shield")
    print(frozen_shield)

    


if __name__ == '__main__':
    main()
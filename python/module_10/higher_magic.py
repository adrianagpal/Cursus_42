from typing import Callable

def fireball(target: str, power: int) -> str:
    return f"Fireball deals {power} damage on {target}"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def spell_combiner(spell1: Callable, spell2: Callable)-> Callable:

    return lambda x: (spell1, spell2)


print(spell_combiner(fireball, heal))

#def power_amplifier(base_spell: Callable, multiplier: int)-> Callable
#def conditional_caster(condition: Callable, spell: Callable)-> Callable
#def spell_sequence(spells: list[Callable])-> Callable


test_values = [8, 25, 20]
test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']
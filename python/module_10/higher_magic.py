from typing import Callable

def fireball(target: str, power: int) -> str:
    return f"Fireball deals {power} damage on {target}"


def heal(target: str, power: int) -> str:
    return f"Heal restores {target} for {power} HP"


def spell_combiner(spell1: Callable, spell2: Callable)-> Callable:

    def combined(target, power):

        return (spell1(target, power), spell2(target, power))

    return combined


def power_amplifier(base_spell: Callable, multiplier: int)-> Callable:

    def combined(target, power):

        amplified_power = power * multiplier
        return base_spell(target, amplified_power)
    
    return combined


def conditional_caster(condition: Callable, spell: Callable)-> Callable:

    def combined(target, power):
        if condition(target, power):
            return spell(target, power)
        return "Spell fizzled"

    return combined


def spell_sequence(spells: list[Callable])-> Callable:

    def combined(target, power):

        spell_list = []

        for spell in spells:
            spell_list.append(spell(target, power))
        
        return spell_list
    
    return combined

def main() -> None:

    print("Testing spell combiner...")
    combined = spell_combiner(fireball, heal)
    print(combined("Dragon", 8))

    print("Testing power amplifier...")
    power = 10
    amplified = power_amplifier(fireball, 3)

if __name__ == '__main__':
    main()

test_values = [8, 25, 20]
test_targets = ['Dragon', 'Goblin', 'Wizard', 'Knight']



#!/usr/bin/env python3

from light_validator import validate_ingredients

def light_spell_allowed_ingredients():
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str):
    if validate_ingredients(ingredients):
        return f"Spell recorded: {spell_name} ({ingredients} - {validate_ingredients(ingredients)})"

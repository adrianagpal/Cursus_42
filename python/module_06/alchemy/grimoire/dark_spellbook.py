#!/usr/bin/env python3

def dark_spell_allowed_ingredients():
    return ["bags", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str):
    if validate_ingredients(ingredients) == "VALID":
        return "VALID"
    return "INVALID"

#!/usr/bin/env python3

from light_spellbook import light_spell_allowed_ingredients

def validate_ingredients(ingredients: str):
    parts = ingredients.split(" ").strip(",")
    flag = "INVALID"
    for ingredient in parts:
        if ingredient in light_spell_allowed_ingredients():
            flag = "VALID"
    return flag

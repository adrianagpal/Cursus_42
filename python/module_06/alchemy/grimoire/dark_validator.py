#!/usr/bin/env python3

def validate_ingredients(ingredients: str):
    flag = "INVALID"
    for ingredient in ingredients:
        if ingredient in dark_spell_allowed_ingredients():
            flag = "VALID"
    return (flag, ingredients)
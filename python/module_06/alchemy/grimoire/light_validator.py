def validate_ingredients(ingredients: str) -> str:

    from .light_spellbook import light_spell_allowed_ingredients

    parts = [p.strip(",") for p in ingredients.split()]

    allowed: list[str] = light_spell_allowed_ingredients()

    for ingredient in parts:
        if ingredient in allowed:
            return "VALID"
    return "INVALID"

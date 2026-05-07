from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:

    parts = [p.strip(",") for p in ingredients.split()]

    allowed: list[str] = dark_spell_allowed_ingredients()

    for ingredient in parts:
        if ingredient in allowed:
            return "VALID"
    return "INVALID"

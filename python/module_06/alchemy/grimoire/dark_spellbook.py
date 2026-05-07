from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bags", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    if validate_ingredients(ingredients) == "VALID":
        return (f"Spell recorded: {spell_name} "
                f"({ingredients} - {validate_ingredients(ingredients)})")

    return (f"Spell rejected: {spell_name} "
            f"({ingredients} - {validate_ingredients(ingredients)})")

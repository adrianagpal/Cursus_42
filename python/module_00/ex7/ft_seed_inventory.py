def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    seed_type = seed_type.strip().capitalize()
    if unit == "packets":
        print("%s seeds: %d %s available" % (seed_type, quantity, unit))
    elif unit == "grams":
        print("%s seeds: %d %s total" % (seed_type, quantity, unit))
    elif unit == "area":
        print("%s seeds: covers %d square meters" % (seed_type, quantity))
    else:
        print("Unknown unit type")

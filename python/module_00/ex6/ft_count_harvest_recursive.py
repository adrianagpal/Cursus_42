def ft_count_harvest_recursive(reap: int | None = None, day: int = 1) -> None:
    if reap is None:
        reap = int(input("Days until harvest: "))
    if day > reap:
        print("Harvest time!")
        return
    print(f"Day {day}")
    ft_count_harvest_recursive(reap, day + 1)

def ft_count_harvest_recursive(harvest=None, count=1):
    if harvest is None:
        harvest = int(input("Days until harvest: "))
    if count > harvest:
        print("Harvest time!")
        return
    print(f"Day {count}")
    ft_count_harvest_recursive(harvest, count + 1)

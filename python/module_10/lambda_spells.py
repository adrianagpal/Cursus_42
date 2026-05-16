
"""
sorted already does kind of list comprehension creating a list of sets with the
result of the key function and the item, then applies sort on them.
"""

def artifact_sorter(artifacts: list[dict])-> list[dict]:

    return sorted(artifacts, key= lambda item: item['power'], reverse=True)


"""
filter returns a filter object, which is an iterator. Elements are only
processed when iterate over them.
"""


def power_filter(mages: list[dict], min_power: int)-> list[dict]:

    return list(filter(lambda x: x['power'] < min_power, mages))


def spell_transformer(spells: list[str])-> list[str]:

    return list(map(lambda x: '*'+x+'*', spells))


def mage_stats(mages: list[dict])-> dict:
    max_val: int = max(mages, key=lambda x: x['power'])
    min_val: int = min(mages, key=lambda x: x['power'])
    avg_val: float = round(sum(map(lambda x: x['power'], mages))/ len(mages), 2)

    return {'max_power': max_val, 'min_power': min_val, 'avg_power': avg_val}


def main() -> None:
    artifacts = [{'name': 'Shadow Blade', 'power': 110, 'type': 'accessory'}, 
                 {'name': 'Crystal Orb', 'power': 73, 'type': 'accessory'}, 
                 {'name': 'Earth Shield', 'power': 81, 'type': 'accessory'}, 
                 {'name': 'Ice Wand', 'power': 65, 'type': 'focus'}]
    
    mages = [{'name': 'Storm', 'power': 54, 'element': 'wind'}, 
             {'name': 'Nova', 'power': 68, 'element': 'lightning'}, 
             {'name': 'Zara', 'power': 82, 'element': 'fire'}, 
             {'name': 'Sage', 'power': 66, 'element': 'water'}, 
             {'name': 'Casey', 'power': 73, 'element': 'ice'}]
    
    spells = ['meteor', 'earthquake', 'blizzard', 'flash']
   
    print("Testing artifact sorter...")
    sorted_artifacts = artifact_sorter(artifacts)
    print(f"{sorted_artifacts[0]['name']} ({sorted_artifacts[0]['power']} power) "
          f"comes before {sorted_artifacts[1]['name']} ({sorted_artifacts[1]['power']} power)\n")
    
    print("Testing power filter... (power < 80)")
    filtered_power = power_filter(artifacts, 80)

    for mage in filtered_power:
        print(f"{mage['name']} - {mage['power']} power")
    
    print()
    print("Testing spell transformer...")
    transformed_spells = spell_transformer(spells)
    print(transformed_spells, '\n')

    print("Testing mage stats...")
    stats = mage_stats(artifacts)

    print(f"Strongest mage: {stats['max_power']['name']} "
          f"({stats['max_power']['power']} power)")

    print(f"Weakest mage: {stats['min_power']['name']} "
          f"({stats['min_power']['power']} power)")

    print(f"Average power: {stats['avg_power']} power")


if __name__ == '__main__':
    main()

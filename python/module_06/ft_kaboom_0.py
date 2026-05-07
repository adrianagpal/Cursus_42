#!/usr/bin/env python3

import alchemy.grimoire

ingredients: str = 'Earth, wind and fire'

print("=== Kaboom 0 ===")
print("Using grimoire module directly")
print("Testing record light spell: "
      f"{alchemy.grimoire.light_spell_record('Fantasy', ingredients)}")

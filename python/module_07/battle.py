#!/usr/bin/env python3
from ex0 import factory

print("Testing factory")
flame = factory.FlameFactory()
flame.create_base()
flame.create_evolved()
print()
print("Testing factory")
aqua = factory.AquaFactory()
aqua.create_base()
aqua.create_evolved()
print()

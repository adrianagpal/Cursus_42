from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex0 import CreatureFactory
from ex0.creature import Creature
from ex1.capability import Sproutling, Bloomelle, Shiftling, Morphagon


def test_healing(factory: HealingCreatureFactory):

    print(" base:")
    base: Sproutling = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.heal())

    print(" evolved:")
    evolution: Bloomelle = factory.create_evolved()
    print(evolution.describe())
    print(evolution.attack())
    print(evolution.heal())


def test_transform(factory: TransformCreatureFactory):

    print(" base:")
    base: Shiftling = factory.create_base()
    print(base.describe())
    print(base.attack())
    print(base.transform())
    print(base.attack())
    print(base.revert())

    print(" evolved:")
    evolution: Morphagon = factory.create_evolved()
    print(evolution.describe())
    print(evolution.attack())
    print(evolution.transform())
    print(evolution.attack())
    print(evolution.revert())


def main():

    print("Testing Creature with healing capability")
    heal_factory: HealingCreatureFactory = HealingCreatureFactory()
    test_healing(heal_factory)
    print()

    print("Testing Creature with transform capability")
    transform_factory: TransformCreatureFactory = TransformCreatureFactory()
    test_transform(transform_factory)
    print()


if __name__ == '__main__':
    main()

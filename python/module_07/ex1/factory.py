from abc import ABC, abstractmethod
from ex0 import CreatureFactory

class FlameFactory(CreatureFactory):
    def create_base(self):
        return Flameling()

    def create_evolved(self):
        return Pyrodon()


class AquaFactory(CreatureFactory):
    def create_base(self):
        return Aquabub()

    def create_evolved(self):
        return Torragon()

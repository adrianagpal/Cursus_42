from abc import ABC, abstractmethod
from .creature import Creature, Flameling, Pyrodon, Aquabub, Torragon
from typing import TypeVar, Generic


BaseT = TypeVar("BaseT", bound=Creature)
EvolvedT = TypeVar("EvolvedT", bound=Creature)


class CreatureFactory(Generic[BaseT, EvolvedT], ABC):

    @abstractmethod
    def create_base(self) -> BaseT:
        pass

    @abstractmethod
    def create_evolved(self) -> EvolvedT:
        pass


class FlameFactory(CreatureFactory[Flameling, Pyrodon]):

    def create_base(self) -> Flameling:
        return Flameling()

    def create_evolved(self) -> Pyrodon:
        return Pyrodon()


class AquaFactory(CreatureFactory[Aquabub, Torragon]):

    def create_base(self) -> Aquabub:
        return Aquabub()

    def create_evolved(self) -> Torragon:
        return Torragon()

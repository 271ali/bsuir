from Person import Person
from Child import Child


class Parent(Person):
    def __init__(self, name: str, age: int, children: list[Child]) -> None:
        Person.__init__(self, name, age)
        self.__children: list[Child] = children
        self.__child_supervision: bool = True

    def get_children(self) -> list[Child]:
        return self.__children



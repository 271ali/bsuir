from HardSkill import HardSkill


class EducationalMaterials:
    def __init__(self, name: str, age: int, skill: HardSkill) -> None:
        self.__name: str = name
        self.__age: int = age
        self.__skill: HardSkill = skill

    def get_name(self) -> str:
        return self.__name

    def get_age(self) -> int:
        return self.__age

    def get_skill(self) -> HardSkill:
        return self.__skill



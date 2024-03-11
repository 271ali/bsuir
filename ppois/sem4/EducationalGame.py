from SoftSkill import SoftSkill


class EducationalGame:
    def __init__(self, name: str, skill: SoftSkill) -> None:
        self.__name: str = name
        self.__skill: SoftSkill = skill

    def get_name(self) -> str:
        return self.__name

    def get_skill(self) -> SoftSkill:
        return self.__skill



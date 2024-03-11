from Person import Person
from EducationalGame import EducationalGames
from EducationalMaterials import EducationalMaterials
from SoftSkill import SoftSkill
from HardSkill import HardSkill


class Child(Person):
    def __init__(self, name: str, age: int) -> None:
        Person.__init__(self, name, age)
        self.__group_number: int = -1
        self.__sleepy: bool = False
        self.__hungry: bool = False
        self.__soft_skills: dict[str, int] = {
            SoftSkill.communication.name: 0,
            SoftSkill.physical_endurance.name: 0,
            SoftSkill.patience.name: 0,
            SoftSkill.attentiveness.name: 0
        }
        self.__hard_skills: dict[str, int] = {
            HardSkill.logics.name: 0,
            HardSkill.literacy.name: 0,
            HardSkill.erudition.name: 0,
            HardSkill.creativity.name: 0
        }

    def sleep(self) -> None:
        print(f"{self.__name} is sleeping")
        self.__sleepy = False
        self.__hungry = True

    def eat(self) -> None:
        print(f"{self.__name} is eating")
        self.__hungry = False
        self.__sleepy = True

    def play(self, game: EducationalGames) -> None:
        print(f"{self.__name} plays a {game.get_name()}")
        print(f"{game.get_skill().name} has improved")
        self.__soft_skills[game.get_skill().name] += 1
        self.__sleepy = False
        self.__hungry = True

    def educate(self, material: EducationalMaterials) -> None:
        print(f"{self.__name} educates with {material.get_name()}")
        print(f"{material.get_skill().name} has improved")
        self.__hard_skills[material.get_skill().name] += 1
        self.__sleepy = True

    def get_group_number(self) -> int:
        return self.__group_number

    def get_hungry(self) -> bool:
        return self.__hungry

    def get_sleepy(self) -> bool:
        return self.__sleepy

    def get_soft_skill(self, skill_name: SoftSkill) -> int:
        return self.__soft_skills[skill_name.name]

    def get_hard_skill(self, skill_name: HardSkill) -> int:
        return self.__hard_skills[skill_name.name]

    def get_soft_skills(self) -> dict[str, int]:
        return self.__soft_skills

    def get_hard_skills(self) -> dict[str, int]:
        return self.__hard_skills

    def set_hungry(self, hungry: bool) -> None:
        self.__hungry = hungry

    def set_sleepy(self, sleepy: bool) -> None:
        self.__sleepy = sleepy

    def set_group_number(self, group_number: int) -> None:
        self.__group_number = group_number

from Person import Person
import Parent
import Child
from EducationalGame import EducationalGame
import EducationalMaterials


class Kindergartener(Person):
    def __init__(self, name: str, age: int, group_number: int, experience: int, age_range: tuple[int, int]) -> None:
        Person.__init__(self, name, age)
        self.__age_range: tuple[int, int] = age_range
        self.__experience: int = experience
        self.__present_group = list()
        self.__group: list[Child] = list()
        self.__group_number: int = group_number

    def put_to_bed(self) -> None:
        for child in self.__group:
            child.sleep()

    def feed(self) -> None:
        for child in self.__group:
            child.eat()

    def play(self, games: list[EducationalGame]) -> None:
        for child in self.__present_group:
            min_skill = min(child.get_soft_skills(), key=child.get_soft_skills().get)
            for game in games:
                if game.get_skill().name == min_skill:
                    child.play(game)
                    break

    def educational_process(self, materials: list[EducationalMaterials]) -> None:
        for material in materials:
            for child in self.__present_group:
                if material.get_age() <= child.get_age() < material.get_age() + 3:
                    child.educate(material)

    def send_the_child_home(self, parent: Parent, child: Child) -> None:
        print(f"{parent.name} your child is a genius,thank you!")
        print(f"""
        There are results of the day :
        Soft skills:
        {child.get_soft_skills()}
        Hard skills
        {child.get_hard_skills()}""")
        self.__present_group.remove(child)

    def meet_the_child(self, child: Child, parent: Parent) -> None:
        self.__present_group.append(child)
        print(f"Hello,{parent.name}! Your child is in safe hands")

    def get_experience(self) -> int:
        return self.__experience

    def get_group_number(self) -> int:
        return self.__group_number

    def get_group(self) -> list[Child]:
        return self.__group

    def get_age_range(self) -> tuple[int, int]:
        return self.__age_range

    def get_present_group(self) -> list[Child]:
        return self.__present_group

from Person import Person
import Parent
import Child
from EducationalGame import EducationalGame
import EducationalMaterial


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

    def __choose_children(self) -> list[Child]:
        children: list[Child] = []
        for i in range(len(self.__present_group)):
            print(f"{i + 1}. {self.__present_group[i].get_name()}")
        print("Please choose child or enter 0")
        while True:
            val = int(input(""))
            if val == 0:
                print("Selection completed")
                break
            if self.__present_group[val-1] not in children:
                children.append(self.__present_group[val - 1])
                print("Addition")
            else:
                print("This child is already selected")

            if val > len(self.__present_group):
                print("Uncorrected number,try again")
        return children

    def play(self, games: list[EducationalGame]) -> None:
        while True:
            players = self.__choose_children()
            print(f"{0}. stop playing")
            for i in range(len(games)):
                print(f"{i+1}. {games[i].get_name()}")
            val = int(input("Choose the game:"))
            if val == 0:
                break
            for child in players:
                child.play(games[val-1])

    def educational_process(self, materials: list[EducationalMaterial]) -> None:
        while True:
            smart_guys = self.__choose_children()
            print(f"{0}. stop education")
            for i in range(len(materials)):
                print(f"{i + 1}. {materials[i].get_name()}")
            val = int(input("Choose the material: "))
            if val == 0:
                break
            for child in smart_guys:
                child.educate(materials[val-1])

    def send_the_child_home(self, parent: Parent, child: Child) -> None:
        print(f"{parent.get_name()} your child is a genius,thank you!")
        print(f"""
        There are results of the day :
        Soft skills:
        {child.get_soft_skills()}
        Hard skills
        {child.get_hard_skills()}""")
        self.__present_group.remove(child)

    def meet_the_child(self, child: Child, parent: Parent) -> None:
        self.__present_group.append(child)
        print(f"Hello,{parent.get_name()}! Your child is in safe hands")

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



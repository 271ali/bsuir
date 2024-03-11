from Child import Child
from Parent import Parent
from Kindergartener import Kindergartener
from EducationalMaterials import EducationalMaterials
from EducationalGame import EducationalGame


class Kindergarten:
    def __init__(self, name: str, kindergarteners: list[Kindergartener], educational_plan: list[EducationalMaterials],
                 educational_games: list[EducationalGame], max_group_size: int) -> None:
        self.__name: str = name
        self.__kindergarteners: list[Kindergartener] = kindergarteners
        self.__educational_plan: list[EducationalMaterials] = educational_plan
        self.__educational_games: list[EducationalGame] = educational_games
        self.__max_group_size: int = max_group_size

    def registration(self, group_number: int, child: Child) -> None:
        for kindergartener in self.__kindergarteners:
            if kindergartener.get_group_number() == group_number:
                if self.__max_group_size - len(kindergartener.get_group()) > 0:
                    if kindergartener.get_age_range()[1] >= child.get_age() >= kindergartener.get_age_range()[0]:
                        kindergartener.get_group().append(child)
                        child.set_group_number(group_number)
                        print(f"""
                        {child.get_name()} has been successfully registered in group {kindergartener.get_group_number()} 
                        (Kindergartener: {kindergartener.get_name()})
                        """)
                    else:
                        print(f"""
                        {child.get_name()} is not age appropriate for this group
                        """)
                        break
                else:
                    print(f"There are no free places left in the group {kindergartener.get_group_number()}")
                    break

    def groups_info(self) -> None:
        for kindergartener in self.__kindergarteners:
            print(f"""
            Group №{kindergartener.get_group_number()}
            Kindergartener: {kindergartener.get_name()}
            Experience: {kindergartener.get_experience()} years
            Age range: {kindergartener.get_age_range()[0]}-{kindergartener.get_age_range()[1]}
            Number of remaining seats: {self.__max_group_size - len(kindergartener.get_group())}
            
            """)

    def pick_up_children(self, parent: Parent) -> None:
        for child in parent.get_children():
            for kindergartener in self.__kindergarteners:
                if child.get_group_number() == kindergartener.get_group_number():
                    kindergartener.meet_the_child(child, parent)
                    break
                elif kindergartener == self.__kindergarteners[-1]:
                    print(f"{child.get_name()} is not registered")

    def educate(self, group_number: int) -> None:
        for kindergartener in self.__kindergarteners:
            if kindergartener.get_group_number() == group_number:
                kindergartener.educational_process(self.__educational_plan)
                break

    def play(self, group_number: int) -> None:
        for kindergartener in self.__kindergarteners:
            if kindergartener.get_group_number() == group_number:
                kindergartener.play(self.__educational_games)
                break

    def nutrition(self, group_number: int) -> None:
        for kindergartener in self.__kindergarteners:
            if kindergartener.get_group_number() == group_number:
                kindergartener.feed()
                break

    def nap(self, group_number: int) -> None:
        for kindergartener in self.__kindergarteners:
            if kindergartener.get_group_number() == group_number:
                kindergartener.put_to_bed()
                break

    def send_home(self, parent: Parent) -> None:
        for kindergartener in self.__kindergarteners:
            for child in parent.get_children():
                if child.get_group_number() == kindergartener.get_group_number():
                    kindergartener.send_the_child_home(parent, child)

    def expel(self, child: Child) -> None:
        for kindergartener in self.__kindergarteners:
            for current_child in kindergartener.get_group():
                if current_child == child:
                    child.set_group_number(-1)
                    kindergartener.get_group().remove(child)
                    print(f"""
                        {child.get_name()} was successfully expelled in group {kindergartener.get_group_number()} 
                        (Kindergartener: {kindergartener.get_name()})
                         """)

from Child import Child
from Parent import Parent
from Kindergartener import Kindergartener
from Kindergarten import Kindergarten
from EducationalMaterials import EducationalMaterials
from EducationalGame import EducationalGame
from SoftSkill import SoftSkill
from HardSkill import HardSkill
from save import save_changes
from load import load_changes


def main():

    child1 = Child("Anastasia", 2)  # 1
    child3 = Child("Milana", 4)  # 2
    child5 = Child("Liza", 6)  # 3
    child6 = Child("Maxim", 5)  # 2
    child8 = Child("Egor", 2)  # 1
    child9 = Child("Anastasia", 4)  # 3
    parent1 = Parent("Natalya", 32, [child1])
    parent2 = Parent("Iryna", 33, [child3])
    parent3 = Parent("Tatyana", 35, [child5])
    parent4 = Parent("Yuriy", 29, [child6])
    parent5 = Parent("Dmitry", 30, [child8])
    parent6 = Parent("Elena", 37, [child9])
    kindergartener1 = Kindergartener("Svetlana", 46, 1, 11, (2, 4))
    kindergartener2 = Kindergartener("Olga", 28, 2, 3, (3, 5))
    kindergartener3 = Kindergartener("Natalya", 33, 3, 7, (4, 6))
    game1 = EducationalGame("musical_chairs", SoftSkill.attentiveness)
    game2 = EducationalGame("edible_inedible", SoftSkill.patience)
    game3 = EducationalGame("puzzle", SoftSkill.communication)
    game4 = EducationalGame("catching up", SoftSkill.physical_endurance)
    material1 = EducationalMaterials("ABC", 4, HardSkill.literacy)
    material2 = EducationalMaterials("Arithmetic", 5, HardSkill.logics)
    material3 = EducationalMaterials("Encyclopedia", 6, HardSkill.erudition)
    material4 = EducationalMaterials("Paints", 3, HardSkill.creativity)
    material5 = EducationalMaterials("Fairy tales for listening", 2, HardSkill.creativity)
    start_kindergarten = Kindergarten("№58", [kindergartener1, kindergartener2, kindergartener3],
                                [material1, material2, material3, material4, material5],
                                [game1, game2, game3, game4], 5)
    start_kindergarten.registration(1, child1)
    start_kindergarten.registration(1, child3)
    start_kindergarten.registration(3, child5)
    start_kindergarten.registration(3, child6)
    start_kindergarten.registration(1, child8)
    start_kindergarten.registration(3, child9)
    start_kindergarten.pick_up_children(parent1)
    start_kindergarten.pick_up_children(parent2)
    start_kindergarten.pick_up_children(parent3)
    start_kindergarten.pick_up_children(parent4)
    start_kindergarten.pick_up_children(parent5)
    start_kindergarten.pick_up_children(parent6)
    kindergarten, child = load_changes()
    my_kindergarten = kindergarten or start_kindergarten
    my_child = child or Child("Alisa", 5)
    my_parent = Parent("Iryna", 32, [my_child])
    while True:
        print("""
            Input number of operation:
            0 - Exit
            1 - Groups Info
            2 - Registration
            3 - Start day
            4 - Expel
            5 - Save changes
            """)
        i = int(input("Choose operation: "))
        match i:
            case 0:
                print("Exiting...")
                break
            case 1:
                my_kindergarten.groups_info()
            case 2:
                val = int(input("Enter group_number: "))
                my_kindergarten.registration(val, my_child)
            case 3:
                my_kindergarten.pick_up_children(my_parent)
                while True:
                    print("""
                                Input number of operation:
                                1 - Education
                                2 - Play games
                                3 - Nutrition
                                4 - Nap
                                5- Finish day
                                """)
                    i = int(input("Choose operation: "))
                    match i:
                        case 1:
                            my_kindergarten.educate(my_child.get_group_number())
                        case 2:
                            my_kindergarten.play(my_child.get_group_number())
                        case 3:
                            my_kindergarten.nutrition(my_child.get_group_number())
                        case 4:
                            my_kindergarten.nap(my_child.get_group_number())
                        case 5:
                            my_kindergarten.send_home(my_parent)
                            break
            case 4:
                my_kindergarten.expel(my_child)
            case 5:
                print("Saving data...")
                save_changes(my_kindergarten,my_child)


if __name__ == "__main__":
    main()

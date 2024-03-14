import unittest
from Kindergarten import Kindergarten
from Child import Child
from Parent import Parent
from load import load_for_test
from load import load_for_test_void
from save import save_changes_for_test
from main import build


class TestKindergarten(unittest.TestCase):
    def setUp(self):
        self.my_kindergarten: Kindergarten = build()
        self.child = Child("Alisa", 3)
        self.parent = Parent("Iryna", 32, [self.child])
        self.my_kindergarten.registration(2, self.child)

    def test_registration(self):
        self.assertEqual(self.child.get_group_number(), 2)
        for kindergartener in self.my_kindergarten.get_kindergarteners():
            if kindergartener.get_group_number() == 2:
                self.assertTrue(self.child in kindergartener.get_group())  # add assertion here

    def test_expel(self):
        self.my_kindergarten.expel(2, self.child)
        self.assertEqual(self.child.get_group_number(), -1)
        for kindergartener in self.my_kindergarten.get_kindergarteners():
            if kindergartener.get_group_number() == 2:
                self.assertTrue(self.child not in kindergartener.get_group())

    def test_pick_up(self):
        self.my_kindergarten.pick_up_children(self.parent)
        self.assertTrue(self.child in self.my_kindergarten.get_kindergarteners()[1].get_present_group())

    def test_send_home(self):
        self.my_kindergarten.pick_up_children(self.parent)
        self.my_kindergarten.send_home(self.parent)
        self.assertTrue(self.child not in self.my_kindergarten.get_kindergarteners()[1].get_present_group())

    #def test_educate(self):
     #   self.my_kindergarten.pick_up_children(self.parent)
     #   self.my_kindergarten.educate(2)
      #  self.assertEqual(self.child.get_hard_skill(HardSkill.creativity),1)
      #  self.assertTrue(self.child.get_sleepy())

   # def test_games(self):
     #   self.my_kindergarten.pick_up_children(self.parent)
      #  self.my_kindergarten.play(2)
      # self.assertEqual(self.child.get_soft_skill(SoftSkill.communication), 1)
       # self.assertTrue(self.child.get_hungry())
      #  self.assertTrue(not self.child.get_sleepy())

    def test_nutrition(self):
        self.child.set_hungry(True)
        self.my_kindergarten.pick_up_children(self.parent)
        self.my_kindergarten.nutrition(2)
        self.assertTrue(not self.child.get_hungry())
        self.assertTrue(self.child.get_sleepy())

    def test_nap(self):
        self.child.set_sleepy(True)
        self.my_kindergarten.pick_up_children(self.parent)
        self.my_kindergarten.nap(2)
        self.assertTrue(not self.child.get_sleepy())

    def test_load_exception(self):
        kindergarten, child = load_for_test_void()
        self.assertEqual(kindergarten, None)
        self.assertEqual(child, None)

    def test_load_and_save(self):
        save_changes_for_test(self.my_kindergarten, self.child)
        kindergarten, child = load_for_test()
        self.assertTrue(kindergarten, not None)
        self.assertTrue(child, not None)

if __name__ == '__main__':
    unittest.main()

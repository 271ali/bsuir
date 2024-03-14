from pickle import load


def load_changes():
    with open("info.pickle", "rb") as file:
        try:
            kindergarten = load(file)
            child = load(file)
            return kindergarten, child
        except EOFError:
            print("File does not contain enough data")
            return None, None


def load_for_test():
    with open("test.pickle", "rb") as file:
        try:
            kindergarten = load(file)
            child = load(file)
            return kindergarten, child
        except EOFError:
            print("File does not contain enough data")
            return None, None


def load_for_test_void():
    with open("test_void.pickle", "rb") as file:
        try:
            kindergarten = load(file)
            child = load(file)
            return kindergarten, child
        except EOFError:
            print("File does not contain enough data")
            return None, None

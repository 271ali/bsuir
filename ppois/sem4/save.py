from pickle import dump


def save_changes(kindergarten, child):
    args = [kindergarten, child]
    with open("info.pickle", "wb") as file:
        for i in args:
            dump(i, file)


def save_changes_for_test(kindergarten, child):
    args = [kindergarten, child]
    with open("test.pickle", "wb") as file:
        for i in args:
            dump(i, file)
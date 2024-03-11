from pickle import load


def load_changes():
    with open("info.pickle", "rb") as file:
        try:
            kindergarten, child = load(file)
            return kindergarten, child
        except EOFError:
            # Обработка ошибки, если файл не содержит достаточного количества данных
            print("File does not contain enough data.")
            return None, None



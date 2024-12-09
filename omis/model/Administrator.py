import string
from model.User import User

class Administrator(User):
    def __init__(self, id: int, name: string, email: string, password: string):
        super().__init__(id, name, email, password)
        self.id = id
        self.name = name
        self.email = email

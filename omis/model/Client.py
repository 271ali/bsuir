import string
from model.Reservation import Reservation
from  model.Role import Role
from model.User import User
class Client(User):
    def __init__(self, id: int, name: string, email: string, password: string, reservation_history: list[Reservation],
                 role: Role):
        super().__init__(id, name, email, password)
        self.id = id
        self.name = name
        self.email = email
        self.password = password
        self.reservation_history = reservation_history
        self.role = role

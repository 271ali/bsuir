import string

from controller.Controller import Controller
from model.interfaces.IAuthenticationService import IAuthenticationService
from model.User import User

class IAuthorizationController:
    def register(self, user: User) -> bool:
        pass

    def login(self, email: string, password: string) -> bool:
        pass

class AuthorizationController(Controller,IAuthorizationController):
    def __init__(self, token, current_user):
        super().__init__(current_user)
        self.token = token
        authentication_service=IAuthenticationService()


from model.User import User
from controller.Controller import Controller
from controller.RequestContext import RequestContext
from model.interfaces.IAuthenticationRepository import IAuthenticationRepository
from model.interfaces.IAuthenticationService import IAuthenticationService


class IPersonalInfromationController:
    def get_user(selfid:int)->User:
        pass

class PersonalInfromationController(Controller,IPersonalInfromationController):
    def __init__(self, current_user,token):
        super().__init__(current_user)
        self.token = token



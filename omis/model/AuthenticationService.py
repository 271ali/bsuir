from model.interfaces.IAuthenticationService import IAuthenticationService
from model.interfaces.IAuthenticationRepository import IAuthenticationRepository

class AuthenticationService(IAuthenticationService):
    def __init__(self,authentication_repository: IAuthenticationRepository):
        self.authentication_repository = authentication_repository
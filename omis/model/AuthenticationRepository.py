from  model.interfaces.IAuthenticationRepository import IAuthenticationRepository
class AuthenticationRepository(IAuthenticationRepository):
    def __init__(self,database):
        self.database = database
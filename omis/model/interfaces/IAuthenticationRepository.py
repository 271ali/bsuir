
import string

from model.Client import Client
class IAuthenticationRepository():
    def get_client(self,email:string)->list[Client]:
        pass

    def create_client(self,Client:Client)->bool:
        pass

import string
from model.Client import Client
class IAuthenticationService():
    def login(self,email:string,password:string)->bool:
        pass

    def register(self,Client:Client)->bool:
        pass


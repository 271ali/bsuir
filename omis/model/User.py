import string


class User:
    def __init__(self,id:int,name:string,email:string,password:string):
        self.id = id
        self.name = name
        self.email = email
        self.password = password

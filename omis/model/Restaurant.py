import string
from  model.Administrator import Administrator

class Restaurant:
    def __init__(self,id:int,name:string,location:string,total_tables:int,available_tables:int,administrator:Administrator):
        self.id = id
        self.name = name
        self.location = location
        self.total_tables = total_tables
        self.available_tables = available_tables
        self.administrator = administrator

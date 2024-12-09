import string


class Reservation:
    def __init__(self,id:int,date:string,restaurant_name:string,table_number:int,guests_count:int,status:string):
        self.id = id
        self.date = date
        self.restaurant_name = restaurant_name
        self.table_number = table_number
        self.guests_count = guests_count
        self.status = status


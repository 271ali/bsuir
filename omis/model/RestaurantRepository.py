from  model.interfaces.IRestaurantRepository import IRestaurantRepository

class RestaurantRepository(IRestaurantRepository):
    def __init__(self,database):
        self.database = database

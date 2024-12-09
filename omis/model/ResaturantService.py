from  model.interfaces.IRestaurantRepository import IRestaurantRepository
from  model.interfaces.IRestaurantService import IRestaurantService

class RestaurantService(IRestaurantService):
    def __init__(self,restaurant_repository:IRestaurantRepository):
        self.restaurant_repository = restaurant_repository

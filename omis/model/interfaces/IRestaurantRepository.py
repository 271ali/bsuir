
from model.Restaurant import Restaurant
class IRestaurantRepository():
    def get_restaurants(self) -> list[Restaurant]:
        pass

    def update_availability(self, restaurant: Restaurant) -> bool:
        pass
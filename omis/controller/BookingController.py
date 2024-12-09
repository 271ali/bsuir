from model.Reservation import Reservation
from model.Reservation import Reservation
from model.interfaces.IReservationService import IReservationService
from model.interfaces.IReservationService import IReservationService
from controller.Controller import Controller

class IBookingController(Controller):
    def get_lis_of_bookings(self)->list[Reservation]:
        pass
    def create_booking(self,reservation: Reservation)->bool:
        pass
    def update_booking(self,reservation: Reservation)->bool:
        pass
    def cancel_booking(self,reservation: Reservation)->bool:
        pass

class BookingController(IBookingController):
    def __init__(self, token, current_user):
        super().__init__(current_user)
        self.booking_service=IReservationService()
        self.token=token


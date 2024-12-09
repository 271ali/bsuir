from model.Reservation import Reservation
class IReservationRepository():
    def get_reservations(self )->list[Reservation]:
        pass

    def create_reservation(self,reservation:Reservation)->bool:
        pass


    def cancel_reservation(self, reservation_id: int) -> bool:
        pass
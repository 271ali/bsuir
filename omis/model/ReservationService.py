from  model.interfaces.IReservationService import IReservationService
from  model.interfaces.IReservationRepository import IReservationRepository
class ReservationService(IReservationService):
    def __init__(self,reservation_repository:IReservationRepository):
        self.reservation_repository = reservation_repository

from  model.interfaces.IReservationRepository import IReservationRepository
class ReservationRepository(IReservationRepository):
    def __init__(self,database):
        self.database = database
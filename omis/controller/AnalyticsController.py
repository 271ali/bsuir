from controller.Controller import Controller
from model.Reservation import Reservation
class Report:
    def __init__(self):
        self.reservations:[Reservation] = []

    def add(self, reservation: Reservation):
        self.reservations.append(reservation)

class IAnalyticsController:
    def get_report(self,reservation:Reservation)->Report:
        pass
    def send_by_email(self,report:Report)->bool:
        pass

class AnalyticsController(Controller,IAnalyticsController):
    def __init__(self, current_user,token):
        super().__init__(current_user)
        self.token = token
    
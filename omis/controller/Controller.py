import abc
from model.Role import Role
class Controller(metaclass=abc.ABCMeta):
    def __init__(self,current_user):
        self.window_factory = WindowFactory()
        self.current_user = current_user
    @abc.abstractmethod
    def check_role(role:Role)->bool:
        pass


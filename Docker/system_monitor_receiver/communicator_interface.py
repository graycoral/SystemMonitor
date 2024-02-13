from abc import ABC, abstractmethod

class ICommunicator(ABC):
    @abstractmethod
    def send(self, message: str) -> None:
        pass

    @abstractmethod
    def receive(self) -> str:
        pass
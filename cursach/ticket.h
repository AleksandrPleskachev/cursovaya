#pragma once
#include <string>

class Ticket {
public:
    // онструктор, который принимает параметры и инициализирует приватные переменные
    Ticket(std::string destination, int flightNumber, std::string passengerName, std::string departureDate);

    // √еттеры дл€ доступа к приватным переменным
    std::string getDestination();
    int getFlightNumber();
    std::string getPassengerName();
    std::string getDepartureDate();

private:
    // ѕриватные переменные класса
    std::string destination;
    int flightNumber;
    std::string passengerName;
    std::string departureDate;
};
#include "ticket.h"

Ticket::Ticket(std::string destination, int flightNumber, std::string passengerName, std::string departureDate) {
    this->destination = destination;
    this->flightNumber = flightNumber;
    this->passengerName = passengerName;
    this->departureDate = departureDate;
}
// Геттеры приватных переменных класса

std::string Ticket::getDestination() {
    return destination;
}

int Ticket::getFlightNumber() {
    return flightNumber;
}

std::string Ticket::getPassengerName() {
    return passengerName;
}

std::string Ticket::getDepartureDate() {
    return departureDate;
}
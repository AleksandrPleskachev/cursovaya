#include "ticketmanager.h"
#include <iostream>

void TicketManager::addTicket(Ticket ticket) {
    tickets.push_back(ticket); //Проимходит добавления заявки в конец списка
}

void TicketManager::removeTicket(int flightNumber, std::string departureDate) {
    auto it = tickets.begin();
    while (it != tickets.end()) {
        if (it->getFlightNumber() == flightNumber && it->getDepartureDate() == departureDate) {
            it = tickets.erase(it);
        }
        else {
            ++it; // Функция проверяет все заявки из списка, ищет соответствие с введенными данными, если это соответствие имеется, заявка удаляется
        }
    }
}

void TicketManager::displayTickets() {
    for (Ticket& ticket : tickets) {
        std::cout << "Пункт назначения: " << ticket.getDestination() << ", Номер рейса: " << ticket.getFlightNumber() << ", Имя пассажира: " << ticket.getPassengerName() << ", Дата вылета: " << ticket.getDepartureDate() << std::endl;
    }
} // Функция проходит по всему списку заявок и выводит все их параметры.

void TicketManager::displayTicketsByFlightAndDate(int flightNumber, std::string departureDate) {
    for (Ticket& ticket : tickets) {
        if (ticket.getFlightNumber() == flightNumber && ticket.getDepartureDate() == departureDate) {
            std::cout << "Пункт назначения: " << ticket.getDestination() << ", Номер рейса: " << ticket.getFlightNumber() << ", Имя пассажира: " << ticket.getPassengerName() << ", Дата вылета: " << ticket.getDepartureDate() << std::endl;
        }
    }
} // Функция проходит по всему списку заявок, учитывая введенные данные. Если заявка из списка имеет те же данные то программа выводит все ее параметры

void TicketManager::readTicketsFromFile(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string destination;
        int flightNumber;
        std::string passengerName;
        std::string departureDate;

        while (file >> destination >> flightNumber >> passengerName >> departureDate) {
            Ticket ticket(destination, flightNumber, passengerName, departureDate);
            tickets.push_back(ticket);
        }

        file.close();
    }
    else {
        std::cerr << "Ошибка при открытии файла." << std::endl;
    }
}
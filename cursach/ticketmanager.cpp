#include "ticketmanager.h"
#include <iostream>

void TicketManager::addTicket(Ticket ticket) {
    tickets.push_back(ticket); //���������� ���������� ������ � ����� ������
}

void TicketManager::removeTicket(int flightNumber, std::string departureDate) {
    auto it = tickets.begin();
    while (it != tickets.end()) {
        if (it->getFlightNumber() == flightNumber && it->getDepartureDate() == departureDate) {
            it = tickets.erase(it);
        }
        else {
            ++it; // ������� ��������� ��� ������ �� ������, ���� ������������ � ���������� �������, ���� ��� ������������ �������, ������ ���������
        }
    }
}

void TicketManager::displayTickets() {
    for (Ticket& ticket : tickets) {
        std::cout << "����� ����������: " << ticket.getDestination() << ", ����� �����: " << ticket.getFlightNumber() << ", ��� ���������: " << ticket.getPassengerName() << ", ���� ������: " << ticket.getDepartureDate() << std::endl;
    }
} // ������� �������� �� ����� ������ ������ � ������� ��� �� ���������.

void TicketManager::displayTicketsByFlightAndDate(int flightNumber, std::string departureDate) {
    for (Ticket& ticket : tickets) {
        if (ticket.getFlightNumber() == flightNumber && ticket.getDepartureDate() == departureDate) {
            std::cout << "����� ����������: " << ticket.getDestination() << ", ����� �����: " << ticket.getFlightNumber() << ", ��� ���������: " << ticket.getPassengerName() << ", ���� ������: " << ticket.getDepartureDate() << std::endl;
        }
    }
} // ������� �������� �� ����� ������ ������, �������� ��������� ������. ���� ������ �� ������ ����� �� �� ������ �� ��������� ������� ��� �� ���������

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
        std::cerr << "������ ��� �������� �����." << std::endl;
    }
}
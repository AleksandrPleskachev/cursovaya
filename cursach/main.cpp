#include <iostream>
#include "ticketmanager.h"

int main() {
    std::system("chcp 1251");
    setlocale(LC_ALL, "");
    TicketManager ticketManager;

    bool running = true;
    while (running) {
        std::cout << "1. �������� ������" << std::endl;
        std::cout << "2. ������� �����" << std::endl;
        std::cout << "3. ������� ��� ������" << std::endl;
        std::cout << "4. ������� ������ �� ���� � ������ �����" << std::endl;
        std::cout << "5. ������� ������ �� �����" << std::endl;
        std::cout << "6. �����" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string destination, passengerName, departureDate;
            int flightNumber;
            std::cout << "������� ����� ����������, ����� ������, ��� ���������, ���� ������: ";
            std::cin >> destination >> flightNumber >> passengerName >> departureDate;
            Ticket ticket(destination, flightNumber, passengerName, departureDate);
            ticketManager.addTicket(ticket);
            break;
        }
        case 2: {
            int flightNumber;
            std::string departureDate;
            std::cout << "������� ����� ����� � ���� ������ ��� ��������: ";
            std::cin >> flightNumber >> departureDate;
            ticketManager.removeTicket(flightNumber, departureDate);
            break;
        }
        case 3:
            ticketManager.displayTickets();
            break;

        case 4: {
            int flightNumber;
            std::string departureDate;
            std::cout << "������� ����� ����� � ���� ������ ��� ������: ";
            std::cin >> flightNumber >> departureDate;
            ticketManager.displayTicketsByFlightAndDate(flightNumber, departureDate);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "������� ��� �����, �� �������� ����� ������� ������: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            ticketManager.readTicketsFromFile(filename);
            break;
        }
        case 6:
            running = false;
            break;
        default:
            std::cout << "�������������� �������. ���������� ��� ���" << std::endl;
            break;
        }
    }

    return 0;
}
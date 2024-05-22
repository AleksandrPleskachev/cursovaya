#include <iostream>
#include "ticketmanager.h"

int main() {
    std::system("chcp 1251");
    setlocale(LC_ALL, "");
    TicketManager ticketManager;

    bool running = true;
    while (running) {
        std::cout << "1. Добавить заявку" << std::endl;
        std::cout << "2. Удалить завку" << std::endl;
        std::cout << "3. Вывести все заявки" << std::endl;
        std::cout << "4. Вывести заявки по дате и номеру рейса" << std::endl;
        std::cout << "5. Считать заявки из файла" << std::endl;
        std::cout << "6. Выход" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string destination, passengerName, departureDate;
            int flightNumber;
            std::cout << "Введите пункт назначения, Номер полета, Имя пассажира, Дату вылета: ";
            std::cin >> destination >> flightNumber >> passengerName >> departureDate;
            Ticket ticket(destination, flightNumber, passengerName, departureDate);
            ticketManager.addTicket(ticket);
            break;
        }
        case 2: {
            int flightNumber;
            std::string departureDate;
            std::cout << "Введите номер рейса и дату вылета для удаления: ";
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
            std::cout << "Введите номер рейса и дату вылета для вывода: ";
            std::cin >> flightNumber >> departureDate;
            ticketManager.displayTicketsByFlightAndDate(flightNumber, departureDate);
            break;
        }
        case 5: {
            std::string filename;
            std::cout << "Введите имя файла, из которого нужно считать билеты: ";
            std::cin.ignore();
            std::getline(std::cin, filename);
            ticketManager.readTicketsFromFile(filename);
            break;
        }
        case 6:
            running = false;
            break;
        default:
            std::cout << "Несуществующая функция. Попробуйте еще раз" << std::endl;
            break;
        }
    }

    return 0;
}
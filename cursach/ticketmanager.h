#pragma once
#include "ticket.h"
#include <list>
#include <fstream>

class TicketManager {
public:
    // Методы класса 
    void addTicket(Ticket ticket); // Функция добавления заявки
    void removeTicket(int flightNumber, std::string departureDate); // Функция удаления заявки
    void displayTickets(); // Функция вывода заявок
    void displayTicketsByFlightAndDate(int flightNumber, std::string departureDate); // Функция вывода заявок по номеру рейса и дате
    void readTicketsFromFile(std::string filename); // Функция считывания данных с файла

private:
    // Приватный список всех заявок
    std::list<Ticket> tickets;
};
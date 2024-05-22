#pragma once
#include "ticket.h"
#include <list>
#include <fstream>

class TicketManager {
public:
    // ������ ������ 
    void addTicket(Ticket ticket); // ������� ���������� ������
    void removeTicket(int flightNumber, std::string departureDate); // ������� �������� ������
    void displayTickets(); // ������� ������ ������
    void displayTicketsByFlightAndDate(int flightNumber, std::string departureDate); // ������� ������ ������ �� ������ ����� � ����
    void readTicketsFromFile(std::string filename); // ������� ���������� ������ � �����

private:
    // ��������� ������ ���� ������
    std::list<Ticket> tickets;
};
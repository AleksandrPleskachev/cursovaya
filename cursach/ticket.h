#pragma once
#include <string>

class Ticket {
public:
    //�����������, ������� ��������� ��������� � �������������� ��������� ����������
    Ticket(std::string destination, int flightNumber, std::string passengerName, std::string departureDate);

    // ������� ��� ������� � ��������� ����������
    std::string getDestination();
    int getFlightNumber();
    std::string getPassengerName();
    std::string getDepartureDate();

private:
    // ��������� ���������� ������
    std::string destination;
    int flightNumber;
    std::string passengerName;
    std::string departureDate;
};
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// ��������� ��� ��� �������� �����
struct Birthday
{
    std::string name;
    int year;
    int month;
    int day;
};

// ������� ��� ���������� ���������� ��� ��������
void calculateNearestBirthday(std::vector<Birthday>& birthdays)
{
    std::time_t now = std::time(nullptr);
    std::tm today = *std::localtime(&now);

    std::tm nextBirthday = today;
    nextBirthday.tm_year += 1; // ��������� ���

    for (const auto& bday : birthdays)
    {
        nextBirthday.tm_mon = bday.month - 1;
        nextBirthday.tm_mday = bday.day;

        std::time_t nextBdayTime = std::mktime(&nextBirthday);

        if (std::difftime(nextBdayTime, now) > 0)
        {
            std::tm nearestBday = *std::localtime(&nextBdayTime);
            std::cout << "��������� ���� ��������: " << nearestBday.tm_mon + 1 << "/" << nearestBday.tm_mday << " - " << bday.name << std::endl;
        }
    }
}

void task2()
{
    std::vector<Birthday> birthdays;

    while (true)
    {
        Birthday bday;
        std::cout << "������� ��� ����� (��� ���������� ������� 'end'): ";
        std::cin >> bday.name;

        if (bday.name == "end")
        {
            break;
        }

        std::cout << "������� ���� �������� � ������� ���/�����/����: ";
        std::string bdayStr;
        std::cin >> bdayStr;

        std::istringstream ss(bdayStr);
        char separator;
        ss >> bday.year >> separator >> bday.month >> separator >> bday.day;

        birthdays.push_back(bday);
    }
    calculateNearestBirthday(birthdays);
}
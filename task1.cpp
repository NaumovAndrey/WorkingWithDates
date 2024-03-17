#include <iostream>
#include <ctime>
#include <string>
#include <map>

// ������� ��� ������� ������� � �����
double calculateHours(std::time_t start, std::time_t end)
{
    return std::difftime(end, start) / 3600.0; // ������� � ��������, ��������� � ����
}

void task1()
{
    std::map<std::string, double> tasks; // �������� ����� � �������
    std::time_t startTime = 0;
    std::string currentTask;

    std::string command;
    while (true)
    {
        std::cout << "������� ������� (begin/end/status/exit): ";
        std::cin >> command;

        if (command == "begin")
        {
            if (startTime != 0)
            {
                // ��������� ���������� ������
                std::time_t endTime = std::time(nullptr);
                tasks[currentTask] += calculateHours(startTime, endTime);
            }
            // ����� ������
            std::cin.ignore(); // �������� ����� �����
            std::cout << "������� �������� ������: ";
            std::getline(std::cin, currentTask);
            startTime = std::time(nullptr);
        } else if (command == "end")
        {
            if (startTime != 0)
            {
                std::time_t endTime = std::time(nullptr);
                tasks[currentTask] += calculateHours(startTime, endTime);
                startTime = 0;
            }
        } else if (command == "status")
        {
            for (const auto& task : tasks)
            {
                std::cout << "������: " << task.first << ", ����� (�): " << task.second << std::endl;
            }
            if (startTime != 0)
            {
                std::cout << "������� ������: " << currentTask << std::endl;
            }
        } else if (command == "exit")
        {
            break; 
        } else
        {
            std::cout << "������������ �������. ���������� �����." << std::endl;
        }
    }
}
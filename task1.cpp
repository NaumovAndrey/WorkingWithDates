#include <iostream>
#include <ctime>
#include <string>
#include <map>

// Функция для расчета времени в часах
double calculateHours(std::time_t start, std::time_t end)
{
    return std::difftime(end, start) / 3600.0; // Разница в секундах, переводим в часы
}

void task1()
{
    std::map<std::string, double> tasks; // Хранение задач и времени
    std::time_t startTime = 0;
    std::string currentTask;

    std::string command;
    while (true)
    {
        std::cout << "Введите команду (begin/end/status/exit): ";
        std::cin >> command;

        if (command == "begin")
        {
            if (startTime != 0)
            {
                // Завершаем предыдущую задачу
                std::time_t endTime = std::time(nullptr);
                tasks[currentTask] += calculateHours(startTime, endTime);
            }
            // Новая задача
            std::cin.ignore(); // Очистить буфер ввода
            std::cout << "Введите название задачи: ";
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
                std::cout << "Задача: " << task.first << ", Время (ч): " << task.second << std::endl;
            }
            if (startTime != 0)
            {
                std::cout << "Текущая задача: " << currentTask << std::endl;
            }
        } else if (command == "exit")
        {
            break; 
        } else
        {
            std::cout << "Некорректная команда. Попробуйте снова." << std::endl;
        }
    }
}
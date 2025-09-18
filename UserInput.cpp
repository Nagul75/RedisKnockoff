//
// Created by regal on 9/17/25.
//

#include "UserInput.h"

std::pair<std::string, std::string> UserInput::getKeyValue()
{
    std::string key{};
    std::string value{};
    while (true)
    {
        std::cout << "Enter key: ";
        std::getline(std::cin >> std::ws, key);
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cout << "Enter value: ";
        std::getline(std::cin >> std::ws, value);
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return {key, value};
    }
}

std::string UserInput::getKey()
{
    std::string key{};
    while (true)
    {
        std::cout << "Enter key: ";
        std::getline(std::cin >> std::ws, key);
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return key;
    }
}

std::string UserInput::getInstance()
{
    std::string instance{};
    while (true)
    {
        std::cout << "Enter instance: ";
        std::getline(std::cin >> std::ws, instance);
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(1);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return instance;
    }
}

char UserInput::yesOrNo()
{
    char choice{};
    while (true)
    {
        std::cin >> choice;
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 'y' || choice == 'n')
        {
            return choice;
        }
    }
}

int UserInput::getCommand()
{
    int choice{};
    while (true)
    {
        std::cout << "Enter command: ";
        std::cin >> choice;
        if (!std::cin)
        {
            if (std::cin.eof()) std::exit(0);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice > 0 && choice < 9)
        {
            return choice;
        }
    }
}


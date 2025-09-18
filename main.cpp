//
// Created by regal on 9/15/25.
//

#include <iostream>
#include "IndexMap.h"
#include "Engine.h"
#include "UserInput.h"
#include <filesystem>

void printMenu()
{
    std::cout << "1. Put data \n2. Get Data \n3. Delete Data \n4. Swap Instance \n5. Create Instance \n6. Update Instance \n7. Delete Instance \n8. Exit \n";
}

bool checkInstanceExists(const std::string& instance)
{
    if (!std::filesystem::is_directory(instance)) return false;
    return true;
}


int main()
{
    std::string instance{};
    while (true)
    {
        instance = UserInput::getInstance();
        if (!checkInstanceExists(instance))
        {
            std::cout << "Instance doesn't exist, create new (y/n)?";
            const char choice{UserInput::yesOrNo()};
            if (choice == 'y')
            {
                RK::Engine::createInstance(instance);
                break;
            }
        }
        else
        {
            break;
        }
    }
    RK::Engine database{instance};
    RK::IndexMap indexMap{instance};
    while (true)
    {
        printMenu();
        const int choice{UserInput::getCommand()};
        if (choice == 8)
        {
            break;
        }
        switch (choice)
        {
        case 1:
            {
                std::pair<std::string, std::string> data{UserInput::getKeyValue()};
                database.putData(data, indexMap);
                break;
            }
        case 2:
            {
                std::string key{UserInput::getKey()};
                std::string value{database.getData(key, indexMap)};
                std::cout << key << ": " << value << '\n';
                break;
            }
        case 3:
            {
                std::string key{UserInput::getKey()};
                database.deleteData(key, indexMap);
                break;
            }
        case 4:
            {
                const std::string inst{UserInput::getInstance()};
                database.swapInstance(inst, indexMap);
                break;
            }
        case 5:
            {
                const std::string inst{UserInput::getInstance()};
                RK::Engine::createInstance(inst);
                break;
            }
        case 6:
            {
                const std::string inst{UserInput::getInstance()};
                database.updateInstance(inst, indexMap);
                break;
            }
        case 7:
            {
                const std::string inst{UserInput::getInstance()};
                database.deleteInstance(inst, indexMap);
                break;
            }
        default:
            {
                std::cout << "??? \n";
                break;
            }
        }
    }
    return 0;
}
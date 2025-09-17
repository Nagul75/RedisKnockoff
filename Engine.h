//
// Created by regal on 9/15/25.
//

#ifndef REDISKNOCKOFF_ENGINE_H
#define REDISKNOCKOFF_ENGINE_H

#include <string>
#include <fstream>

namespace RK
{
    class Engine
    {
    public:
        explicit Engine(const std::string& instance);

        bool putData(std::pair<std::string, std::string>& pair);
        bool getData(std::string& key);
        bool deleteData(std::string& key);

        bool putInstance(std::string& instance);
        bool deleteInstance(std::string& instance);
        bool swapInstance(std::string& instance);

    private:
        std::string m_instance{};
        std::fstream m_instanceDataFile{};
    };
}

#endif //REDISKNOCKOFF_ENGINE_H
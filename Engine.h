//
// Created by regal on 9/15/25.
//

#ifndef REDISKNOCKOFF_ENGINE_H
#define REDISKNOCKOFF_ENGINE_H

#include <string>
#include <fstream>
#include "IndexMap.h"

namespace RK
{
    class Engine
    {
    public:
        explicit Engine(const std::string& instance);

        bool putData(const std::pair<std::string, std::string>& pair, RK::IndexMap& indexMap);
        std::string getData(const std::string& key, RK::IndexMap& indexMap);
        bool deleteData(const std::string& key, RK::IndexMap& indexMap);
        void openData();

        bool putInstance(std::string& instance);
        bool deleteInstance(std::string& instance);
        bool swapInstance(std::string& instance);

    private:
        std::string m_instance{};
        std::fstream m_instanceDataFile{};
    };
}

#endif //REDISKNOCKOFF_ENGINE_H
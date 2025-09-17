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

        static bool createInstance(const std::string& instance);
        static bool updateInstance(std::string& oldInstance, std::string& newInstance);
        static bool deleteInstance(const std::string& instance);

        bool swapInstance(const std::string& instance, RK::IndexMap& indexMap);

    private:
        std::string m_instance{};
        std::fstream m_instanceDataFile{};
    };
}

#endif //REDISKNOCKOFF_ENGINE_H
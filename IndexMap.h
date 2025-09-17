//
// Created by regal on 9/15/25.
//

#ifndef REDISKNOCKOFF_INDEXMAP_H
#define REDISKNOCKOFF_INDEXMAP_H

#include <unordered_map>
#include <string>
#include <fstream>
namespace RK
{
    class IndexMap
    {
    public:
        explicit IndexMap(const std::string& instance);
        ~IndexMap();

        std::unordered_map<std::string, std::streampos>& getIndices() {return m_indices;}
        void openIndex();
        void closeIndex();
        void addIndex(const std::string& key, std::streampos pos);
        void removeIndex(const std::string& key);
        std::streampos get(const std::string& key);

        void setInstance(const std::string& instance){m_instance = instance;}
    private:
        std::unordered_map<std::string, std::streampos> m_indices{}; // key : bytes
        std::fstream m_indexFile{};
        std::string m_instance{};
    };
}

#endif //REDISKNOCKOFF_INDEXMAP_H
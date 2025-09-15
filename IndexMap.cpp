//
// Created by regal on 9/15/25.
//

#include "IndexMap.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>


RK::IndexMap::IndexMap(const std::string& instance)
    :m_instance(instance)
{
    m_indices.clear();
    m_indexFile.open(instance, std::ios::in | std::ios::out | std::ios::app);
    if (!m_indexFile.is_open())
    {
        std::cerr << "Error opening index \n";
    }
    std::string line{};
    while (std::getline(m_indexFile, line))
    {
        std::stringstream ss{line};
        std::string cell{};
        std::vector<std::string> row{};
        while (std::getline(ss, cell, ','))
        {
            row.emplace_back(cell);
        }

        m_indices[row[0]] = std::stoll(row[1]);
    }
    m_indexFile.close();
    std::cout << "Finished reading file \n";
}


RK::IndexMap::~IndexMap()
{
    std::cout << "Saving index file.\n";
    m_indexFile.open(m_instance, std::ios::out | std::ios::trunc); // Overwrite the file on shutdown
    if (m_indexFile.is_open())
    {
        for (const auto& pair : m_indices)
        {
            m_indexFile << pair.first << "," << pair.second << '\n';
        }
        m_indexFile.close();
        std::cout << "Index file saved successfully.\n";
    }
    else
    {
        std::cerr << "Error saving index file.\n";
    }
}

void RK::IndexMap::addIndex(const std::string& key, const std::streampos pos)
{
    m_indices[key] = pos;
}

void RK::IndexMap::removeIndex(const std::string& key)
{
    m_indices.erase(key);
}

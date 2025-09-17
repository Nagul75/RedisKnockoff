//
// Created by regal on 9/15/25.
//

#include "Engine.h"
#include <iostream>
#include <filesystem>
#include <vector>


//helper functions --start--

void create_new_instance(const std::string& instance)
{
    std::cout << "Creating new instance directory with instance files \n";
    // Construct the full path for the new directory.
    // The relative path "." means the current working directory.
    std::filesystem::path instance_path = std::filesystem::current_path() / instance;

    // Create the directory using the full path.
    std::filesystem::create_directory(instance_path);

    // Construct the file paths relative to the new directory.
    std::ofstream dataFile(instance_path / (instance + "_data.txt"));
    std::ofstream indexFile(instance_path / (instance + "_index.txt"));

    if (!dataFile.is_open() || !indexFile.is_open()) // Use logical OR here
    {
        std::cerr << "Error creating instance files \n";
    }
}

//overloading std::pair ostream
template <typename T, typename U>
std::ostream& operator<<(std::ostream& out, const std::pair<T, U>& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

//Engine implementation
RK::Engine::Engine(const std::string& instance)
    :m_instance(instance)
{
    std::string dataFilePath = m_instance + "/" + m_instance + "_data.txt";

    // Check if the directory exists first.
    if (!std::filesystem::exists(m_instance))
    {
        create_new_instance(m_instance);
    }

    m_instanceDataFile.open(dataFilePath, std::ios::in | std::ios::out | std::ios::app);
    if (!m_instanceDataFile.is_open())
    {
        std::cerr << "Cannot open instance data at path: " << dataFilePath << "\n";
        // Consider throwing an exception here to signal a fatal error.
        return;
    }
    std::cout << "Successfully opened instance data file.\n";
}

std::string RK::Engine::getData(const std::string& key, RK::IndexMap& indexMap)
{
    const std::streampos offset {indexMap.get(key)};
    if (offset == -1)
    {
        std::cout << "Data not found \n";
        return "";
    }

    m_instanceDataFile.seekg(offset);
    std::string line{};
    std::getline(m_instanceDataFile, line);
    std::stringstream ss{line};
    std::string cell{};
    std::vector<std::string> row{};
    while (std::getline(ss, cell, ','))
    {
        row.emplace_back(cell);
    }

    return row[1];
}

bool RK::Engine::putData(const std::pair<std::string, std::string>& pair, RK::IndexMap& indexMap)
{
    if (indexMap.get(pair.first) != -1)
    {
        const auto value {getData(pair.first, indexMap)};
        if (value == pair.second)
        {
            std::cerr << "Data already exists, skipping write operation \n";
            return false;
        }
    }
    const std::streampos currentOffset{m_instanceDataFile.tellp()};
    m_instanceDataFile << pair.first << "," << pair.second << "," << "F" << '\n';
    if (m_instanceDataFile.fail())
    {
        std::cerr << "Error writing to data file.\n";
        return false;
    }
    indexMap.addIndex(pair.first, currentOffset);
    std::cout << pair << " successfully inserted \n";
    return true;
}

bool RK::Engine::deleteData(const std::string& key, RK::IndexMap& indexMap)
{
    if (indexMap.get(key) == -1)
    {
        std::cerr << "Data doesn't exist! \n";
        return false;
    }
    const std::string value{getData(key, indexMap)};
    m_instanceDataFile << key << "," << value << "," << "T" << '\n';
    if (m_instanceDataFile.fail())
    {
        std::cerr << "Error deleting data \n";
        return false;
    }
    indexMap.removeIndex(key);
    std::cout << "(" << key << ", " << value << ") deleted successfully \n";
    return true;
}


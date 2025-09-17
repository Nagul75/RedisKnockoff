//
// Created by regal on 9/15/25.
//

#include "Engine.h"
#include <iostream>
#include <filesystem>

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



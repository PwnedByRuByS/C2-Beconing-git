#include "fileManager.hpp"
#include <iostream>
#include <fstream>

void FileManager::saveToFile(const std::string& data, const std::string& filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << data;
        outputFile.close();
        std::cout << "Data saved to: " << filename << std::endl;
    } else {
        std::cerr << "Failed to open file: " << filename << std::endl;
    }
}
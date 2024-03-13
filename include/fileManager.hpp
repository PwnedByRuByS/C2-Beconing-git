#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <iostream>
class FileManager {
public:
    void saveToFile(const std::string& data, const std::string& filename);
};

#endif
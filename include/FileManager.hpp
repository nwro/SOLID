#pragma once
#include <iostream>

class FileManager
{
public:
    void createFile(const std::string& text);
    void createDirectory();
    void overwrite(const std::string& text);
    void append(const std::string& text);
    void remove();
    std::string read();

    void applyFilepath(const std::string& filepath);
private:
    void throwExceptionIfFileDoesntExist(const std::string& path);
    void throwExceptionIfFileExists(const std::string& path);
    void throwExceptionIfDirectoryExists(const std::string& path);
    bool doesFileExist(const std::string& path);
    bool doesDirectoryExist(const std::string& path);
    std::string path;
};
#pragma once
#include <iostream>

class FileManager
{
public:
    void overwrite(const std::string& text);
    void append(const std::string& text);
    void remove();
    std::string read();
    void applyFilepath(const std::string& filepath);

private:
    bool doesFileExist(const std::string& path);
    void throwExceptionIfFileDoesntExist(const std::string& path);
    std::string filepath;
    std::string text;
};
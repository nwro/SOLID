#pragma once
#include <fstream>

class FileWriter
{
public:
    static void overwrite(const std::string& filepath, const std::string& text);
    static void append(const std::string& filepath, const std::string& text);
private:
    static void executeFileWrite(const std::string& filepath, const std::string& text, std::ios_base::openmode mode);
};
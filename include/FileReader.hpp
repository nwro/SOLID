#pragma once
#include <fstream>

class FileReader
{
public:
    static std::string read(const std::string& filepath);
};
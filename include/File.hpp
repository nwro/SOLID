#pragma once
#include <fstream>
#include <iostream>

class File
{
public:
    File(const std::string& filepath, std::ios_base::openmode mode);
    ~File();
    File& operator<<(const std::string& data);
    File& operator>>(std::string& data);
    operator std::istream&();
private:
    std::fstream file;    
};
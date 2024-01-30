#include "File.hpp"

File::File(const std::string& filepath, std::ios_base::openmode mode)
{
    file.open(filepath, mode);
    if (!file.is_open())
        throw std::runtime_error("You don't have permissions to modify this file!");
}

File::~File()
{
    if (file.is_open())
        file.close();
}

File& File::operator<<(const std::string& data)
{
    file << data;
    return *this;
}

File& File::operator>>(std::string& data)
{
    file >> data;
    return *this;
}

File::operator std::istream&()
{
    return file;
}
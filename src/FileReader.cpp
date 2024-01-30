#include "FileReader.hpp"
#include "File.hpp"

std::string FileReader::read(const std::string& filepath)
{
    File file(filepath, std::fstream::in);
    std::string content, line;
    while (std::getline(static_cast<std::istream&>(file), line))
    {
        content += line + '\n';
    }
    return content;
}
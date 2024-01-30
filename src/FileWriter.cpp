#include "FileWriter.hpp"
#include "File.hpp"
#include <iostream>

void FileWriter::overwrite(const std::string& filepath, const std::string& text)
{
    executeFileWrite(filepath, text, std::fstream::out);
}

void FileWriter::append(const std::string& filepath, const std::string& text)
{
    executeFileWrite(filepath, text, std::fstream::out | std::fstream::app);
}

void FileWriter::executeFileWrite(const std::string& filepath, const std::string& text, std::ios_base::openmode mode)
{
    File file(filepath, mode);
    file << text;
}
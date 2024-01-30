#include "FileManager.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"
#include "FileRemover.hpp"

namespace fs = std::filesystem;

void FileManager::overwrite(const std::string& text)
{
    throwExceptionIfFileDoesntExist(filepath);
    FileWriter::overwrite(filepath, text);
}

void FileManager::append(const std::string& text)
{
    throwExceptionIfFileDoesntExist(filepath);
    FileWriter::append(filepath, text);
}

void FileManager::remove()
{
    throwExceptionIfFileDoesntExist(filepath);
    FileRemover::remove(filepath);
}

std::string FileManager::read()
{
    throwExceptionIfFileDoesntExist(filepath);
    return FileReader::read(filepath);
}

void FileManager::applyFilepath(const std::string& filepath)
{
    throwExceptionIfFileDoesntExist(filepath);
    this->filepath = filepath;
}

void FileManager::throwExceptionIfFileDoesntExist(const std::string& path)
{
    if (!doesFileExist(path))
        throw std::runtime_error("File does not exists!");
}

bool FileManager::doesFileExist(const std::string& path)
{
    return fs::exists(path) && fs::is_regular_file(path);
}
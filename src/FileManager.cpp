#include "FileManager.hpp"
#include "FileReader.hpp"
#include "FileWriter.hpp"
#include "FileRemover.hpp"
#include "FileCreator.hpp"

namespace fs = std::filesystem;

void FileManager::createFile(const std::string& text)
{
    throwExceptionIfFileExists(path);
    FileCreator::createRegularFile(path, text);
}

void FileManager::createDirectory()
{
    throwExceptionIfDirectoryExists(path);
    FileCreator::createDirectory(path);
}

void FileManager::overwrite(const std::string& text)
{
    throwExceptionIfFileDoesntExist(path);
    FileWriter::overwrite(path, text);
}

void FileManager::append(const std::string& text)
{
    throwExceptionIfFileDoesntExist(path);
    FileWriter::append(path, text);
}

void FileManager::remove()
{
    throwExceptionIfFileDoesntExist(path);
    FileRemover::remove(path);
}

std::string FileManager::read()
{
    throwExceptionIfFileDoesntExist(path);
    return FileReader::read(path);
}

void FileManager::applyFilepath(const std::string& filepath)
{
    this->path = filepath;
}

void FileManager::throwExceptionIfFileDoesntExist(const std::string& path)
{
    if (!doesFileExist(path))
        throw std::runtime_error("File does not exists!");
}

void FileManager::throwExceptionIfFileExists(const std::string& path)
{
    if (doesFileExist(path))
        throw std::runtime_error("File is existing already!");
}

void FileManager::throwExceptionIfDirectoryExists(const std::string& path)
{
    if (doesDirectoryExist(path))
        throw std::runtime_error("Directory is existing already!");
}

bool FileManager::doesFileExist(const std::string& path)
{
    return fs::exists(path) && fs::is_regular_file(path);
}

bool FileManager::doesDirectoryExist(const std::string& path)
{
    return fs::exists(path) && fs::is_directory(path);
}
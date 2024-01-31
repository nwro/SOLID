#include <filesystem>
#include <random>
#include "FileCreator.hpp"
#include "FileWriter.hpp"

namespace fs = std::filesystem;

void FileCreator::createDirectory(const std::string& path)
{
    fs::create_directory(path);
    fs::permissions(path, fs::perms::owner_all);
}

void FileCreator::createRegularFile(const std::string& path, const std::string& content)
{
    const std::string fingerprint = createFingerprint();
    FileWriter::overwrite(path, content + '\n' + fingerprint);
}

std::string FileCreator::createFingerprint()
{
    return std::to_string(std::time(0)) + " " + std::to_string(getRandom());
}

int FileCreator::getRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);

    return dis(gen);
}
#include "FileRemover.hpp"

namespace fs = std::filesystem;

void FileRemover::remove(const std::string& path)
{
    fs::remove(path);
}
#pragma once
#include <filesystem>

class FileRemover
{
public:
    static void remove(const std::string& path);
};
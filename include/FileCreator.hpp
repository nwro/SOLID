#pragma once

class FileCreator
{
public:
    static void createDirectory(const std::string& path);
    static void createRegularFile(const std::string& path, const std::string& content);

private:
    static std::string createFingerprint();
    static int getRandom();
};
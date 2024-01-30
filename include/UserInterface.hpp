#pragma once
#include <iostream>
#include "FileManager.hpp"

enum Action
{
    EXIT = 0,
    RETURN,
    OVERWRITE,
    APPEND,
    READ,
    REMOVE,
    ActionCOUNT
};

class UserInterface
{
public:
    void run();
private:
    Action getAction();
    
    std::string getFilepath();
    std::string getLines();
    void clearInputBuffer();
    void print(const std::string& output);
    void print(const std::exception& e);
    FileManager fileManager;
};

const std::string commands = 
    "What do you want to do:\n"
    "0. Exit\n"
    "1. Change filepath\n"
    "2. Write to file\n"
    "3. Append file\n" 
    "4. Read file\n"
    "5. Remove file\n"; 
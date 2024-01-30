#include "UserInterface.hpp"

void UserInterface::run()
{
    print("Welcome in file manager!\n");
    while(true)
    {
        try
        {
            fileManager.applyFilepath(getFilepath());

            Action action;
            while((action = getAction()) && action != RETURN)
            {
                switch (action)
                {
                    case OVERWRITE:
                        fileManager.overwrite(getLines());
                        break;
                    case APPEND:
                        fileManager.append(getLines());
                        break;
                    case READ:
                        print(fileManager.read());
                        break;
                    case REMOVE:
                        fileManager.remove();
                        break;
                    case EXIT:
                        exit(0);
                        break;
                    default:
                        break;
                }
                print("Action performed correctly!\n");
                print("Choose your next action\n");
            }
        }
        catch(const std::exception& e)
        {
            print(e);
        }
    }
}

std::string UserInterface::getLines()
{
    std::string result;
    std::string line;
    print("To stop writing to file, write /q in new line\n");
    clearInputBuffer();
    while (std::getline(std::cin, line) && line != "/q")
    {
        result += line + '\n';
    }
    return result;
}

std::string UserInterface::getFilepath()
{
    print("Enter filepath: "); 
    std::string filepath;
    std::cin >> filepath;
    return filepath;
}

Action UserInterface::getAction()
{
    print(commands);
    print("Enter a number: ");

    int action;
    while (!(std::cin >> action) || action >= ActionCOUNT)
    {
        clearInputBuffer();
        print("Invalid input, try again\n");
        print("Enter a number: ");
    }
    
    return Action(action);
}

void UserInterface::clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInterface::print(const std::string& output)
{
    std::cout << output;
}

void UserInterface::print(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}

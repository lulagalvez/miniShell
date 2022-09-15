#include <iostream>
#include <string>

#define clear() printf("\033[H\033[J")

int getInput(std::string &str)
{
    std::string buff;
    printf("$");
    std::getline(std::cin, buff);
    if(buff.length() != 0)
    {
        str = buff;
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    clear();
    while(1)
    {
        std::string str;
        if(getInput(str))
            continue;
        
        std::cout << str << "\n";
    }

    return 0;
}


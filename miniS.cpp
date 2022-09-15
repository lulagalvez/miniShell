#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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

std::vector<std::vector<std::string> > parseString(std::string str)
{
    std::stringstream ss(str);
    std::vector<std::vector<std::string> > strvVector;
    strvVector.push_back(std::vector<std::string>());

    std::string temp;
    int cnt = 0;
    while(ss >> temp)
    {
        if(temp == "|")
        {
            strvVector.push_back(std::vector<std::string>());
            cnt++;
            continue;
        }   
        strvVector[cnt].push_back(temp);
    }
    return strvVector;
}

int main()
{
    clear();
    while(1)
    {
        std::string str;
        if(getInput(str))
            continue;
        
        std::vector<std::vector<std::string> > parsedString = parseString(str);

        for(int i = 0; i < parsedString.size(); i++)
        {
            for(int j = 0; j < parsedString[i].size(); j++)
            {
                std::cout << parsedString[i][j] << ",";
            }    
            std::cout << "\n";
        }

    }

    return 0;
}


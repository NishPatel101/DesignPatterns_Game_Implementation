#include "fileReader.h"

FileReader::FileReader()
{

}

std::vector<std::string> FileReader::loadVector(std::string)
{
    std::string line;
    std::ifstream readFile(file);
    std::vector<std::string>temp;
    
    while(std::getline(readFile,line))
    {
           temp.push_back(line);
    }

    return temp;

}

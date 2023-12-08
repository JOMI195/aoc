#include "stringparser.h"

#include <sstream>

std::vector<std::string> StringParser::toVector(const std::string & str, const std::string & sep)
{
    std::vector<std::string> vec;
    std::string src = str;
    while(src.find(sep) != std::string::npos)
    {
        if (src.find(sep) == 0)
        {

            src = src.substr(sep.size());
        }
        else
        {
            vec.push_back(src.substr(0, src.find(sep)));
            src = src.substr(src.find(sep) + sep.size());
        }
    }
    vec.push_back(src);
    return vec;
}

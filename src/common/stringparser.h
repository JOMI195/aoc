#ifndef AOC_STRINGPARSER_H
#define AOC_STRINGPARSER_H

#include <string>
#include <vector>

class StringParser
{
public:
    static std::vector<std::string> toVector(const std::string &str, const std::string &delimiter);
};


#endif

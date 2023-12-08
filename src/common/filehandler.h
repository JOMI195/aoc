#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <vector>

class FileHandler
{
private:
    std::string _buffer;
public:
    FileHandler(const std::string & filePath);
    std::string getBuffer();
};

#endif
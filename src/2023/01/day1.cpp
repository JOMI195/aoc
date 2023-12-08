#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");
    if (!inFile.is_open()) {
        std::cout << "Unable to open file" << std::endl;
        exit(1);
    }

    std::string line;
    int calVal = 0;
    while ( getline (inFile,line) )
    {
        std::vector<char> char_nums;
        for (size_t i = 0; i < line.size(); i++)
        {
            if (std::isdigit(line[i]))
            {
                char_nums.push_back(line[i]);
            }

            std::string str_num;
            for (size_t t = i; t < line.size(); t++)
            {
                str_num += line[t];
                if (str_num == "one")
                {
                    char_nums.push_back('1');
                }
                else if (str_num == "two")
                {
                    char_nums.push_back('2');
                }
                else if (str_num == "three")
                {
                    char_nums.push_back('3');
                }
                else if (str_num == "four")
                {
                    char_nums.push_back('4');
                }
                else if (str_num == "five")
                {
                    char_nums.push_back('5');
                }
                else if (str_num == "six")
                {
                    char_nums.push_back('6');
                }
                else if (str_num == "seven")
                {
                    char_nums.push_back('7');
                }
                else if (str_num == "eight")
                {
                    char_nums.push_back('8');
                }
                else if (str_num == "nine")
                {
                    char_nums.push_back('9');
                }
            }
        }

        std::string str_num;
        if (char_nums.size() == 1) {
            str_num += char_nums.at(0);
            str_num += char_nums.at(0);
        }
        else
        {
            str_num += char_nums.at(0);
            str_num += char_nums.at(char_nums.size() - 1);
        }
        int digit = std::stoi(str_num);
        calVal += digit;
    }
    std::cout << calVal << '\n';

    inFile.close();
    return 0;
}
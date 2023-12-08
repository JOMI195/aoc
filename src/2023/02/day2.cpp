#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#include "stringparser.h"
#include "filehandler.h"

int part1(const std::vector<std::string>& input) {

    int red = 12, green = 13, blue = 14;

    int sumed_ids = 0;
    for (const std::string& game : input)
    {
        size_t game_id_start = game.find(' ');
        size_t game_id_end = game.find(':');
        std::string str_game_id = game.substr(game_id_start, game_id_end);
        int game_id = std::stoi(str_game_id);
        //std::cout << game_id << "\n";

        std::string games = game.substr(game_id_end + 2, game.size());
        std::vector<std::string> sep_games = StringParser::toVector(games, "; ");
        bool validGame = true;
        for (const std::string& subset : sep_games)
        {
            std::vector<std::string> sets = StringParser::toVector(subset, ", ");
            for (const std::string& set : sets)
            {
                std::vector<std::string> cube = StringParser::toVector(set, " ");
                int amount = std::stoi(cube[0]);
                //std::cout << amount << " " << cube[1] <<  "\n";
                if (cube[1] == "blue" && amount > blue || cube[1] == "red" && amount > red || cube[1] == "green" && amount > green)
                {
                    validGame = false;
                    break;
                }
            }
            if (!validGame)
            {
                break;
            }
        }
        if (validGame)
        {
            sumed_ids += game_id;
        }
        //std::cout << sumed_ids << "\n";
    }
    return sumed_ids;
}

int main()
{
    FileHandler fileHandlerTest("src/2023/02/testinput.txt");
    std::vector<std::string> testInput = StringParser::toVector(fileHandlerTest.getBuffer(), "\n");
    assert(part1(testInput) == 8);

    FileHandler fileHandler("src/2023/02/input.txt");
    std::vector<std::string> input = StringParser::toVector(fileHandler.getBuffer(), "\n");
    std::cout << "Puzzle Solution Day 2 - Part 1: " << part1(input) << "\n";
    return 0;
}
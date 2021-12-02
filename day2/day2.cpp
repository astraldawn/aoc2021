#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

/*
map<string, tuple<string, int>> instruction_map = {
    {"forward", make_tuple("horizontal", 1)},
    {"up", make_tuple("depth", -1)},
    {"down", make_tuple("depth", 1)}};

class Submarine
{
private:
    map<string, int> positions = {{"depth", 0}, {"horizontal", 0}};

public:
    vector<tuple<string, int>> instructions;

    void process() {
        for (auto instruction : instructions) {
            auto [ instruction_type, value ] = instruction;
            auto [ position_type, direction ] = instruction_map[instruction_type];
            positions[position_type] += value * direction;
        }
    }

    void part1() {
        cout << positions["depth"] * positions["horizontal"] << endl;
    }
};*/

map<string, tuple<string, int>> instruction_map = {
    {"forward", make_tuple("horizontal", 1)},
    {"up", make_tuple("aim", -1)},
    {"down", make_tuple("aim", 1)}};

class Submarine
{
private:
    map<string, int> positions = {{"depth", 0}, {"horizontal", 0}, {"aim", 0}};

public:
    vector<tuple<string, int>> instructions;

    void process()
    {
        for (auto instruction : instructions)
        {
            auto [instruction_type, value] = instruction;
            auto [position_type, direction] = instruction_map[instruction_type];

            // Additional movement for forward
            if (instruction_type == "forward")
            {
                positions["depth"] += positions["aim"] * value;
            }

            positions[position_type] += value * direction;
        }
    }

    void part2()
    {
        cout << positions["depth"] * positions["horizontal"] << endl;
    }
};

int main()
{
    int i;

    ifstream infile("part1.in");
    // ifstream infile("test.in");

    string inp_instruction;
    int inp_units;
    Submarine sub;
    while (infile >> inp_instruction >> inp_units)
    {
        sub.instructions.push_back(make_tuple(inp_instruction, inp_units));
    }

    sub.process();
    sub.part2();
    // printf("%d\n", part1(input));
    // printf("%d\n", part2(input));
    return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int part1(vector<int> input)
{
    int previous = 9999999, count = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] > previous)
        {
            count += 1;
        }
        previous = input[i];
    }

    return count;
}

int part2(vector<int> input)
{
    int previous = 9999999, current = 0, count = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (i < 2)
        {
            current += input[i];
        }
        else
        {
            current += input[i];
            if (current > previous)
            {
                count += 1;
            }
            previous = current;
            current -= input[i - 2];
        }
    }

    return count;
}

int main()
{
    int i;
    vector<int> input;
    FILE *inp;

    // inp = fopen("test.in", "r+");
    inp = fopen("part1.in", "r+");
    while (fscanf(inp, "%d\n", &i) != EOF)
    {
        input.push_back(i);
    }

    printf("%d\n", part1(input));
    printf("%d\n", part2(input));
    return 0;
}

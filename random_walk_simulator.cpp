#include <random>
#include <iostream>
#include <vector>
#include <map>
int random_walk(int steps, std::mt19937& engine);




int main()
{
    std::mt19937 engine {std::random_device{}()};
    std::vector<int> final_positions;

    for (size_t i{}; i < 10000; ++i)
    {
        int final_position{random_walk(100, engine)};
        final_positions.push_back(final_position);
    }

    std::map<int,int> histogram;
    for (int final_position : final_positions)
    {
        ++histogram[final_position];
    }



}

int random_walk(int steps, std::mt19937& engine)
{
    std::uniform_int_distribution<int> coin{0, 1};
    int position{};

    for (size_t i{}; i < steps;  ++i)
    {
        int roll {coin(engine)};
        (roll == 1) ? ++position : --position;
    }

    return position;
}
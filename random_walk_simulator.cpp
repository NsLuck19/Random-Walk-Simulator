#include <random>
#include <iostream>
#include <vector>
#include <map>

int random_walk(int steps, std::mt19937& engine);
double mean(const std::vector<int>& data);
double variance(const std::vector<int>& data);

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


    for (const auto& [position, counts] : histogram)
    {
        std::cout << position << "     : "<< std::string(counts/20, '*') << std::endl;
    }
    
    std::cout << "Mean Value: " << mean(final_positions) << std::endl;
    std::cout << "Variance: " << variance(final_positions) << std::endl;
    return 0;


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
double mean(const std::vector<int>& data)
{
    double sum{};
    for ( int value : data)
    {
        sum += static_cast<double>(value);
    }
    return sum / data.size();
    
}
double variance(const std::vector<int>& data)
{
    double sum{};
    double data_mean{mean(data)};

    for (int value : data)
    {
        sum += ((value - data_mean) * (value - data_mean));
    }

    return sum / data.size();


}
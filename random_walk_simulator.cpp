#include <random>

int random_walk(int steps, std::mt19937& engine);




int main()
{
    std::mt19937 engine {std::random_device{}()};

    for (size_t i{}; i < 100 ; ++i)
    {
        random_walk(100);

        std::cout << "Final Position: "
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
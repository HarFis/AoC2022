#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<int> array_int;
    int highest{}; // 25
    int current{};
    array_int = m.read_input_int("input.txt");
    for (auto i = 0; i < array_int.size(); ++i)
    {
        if (array_int[i] == -1)
        {
            if (current > highest)
            {
                highest = current;
            }
            current = 0;
        }
        else
        {
            current+=array_int[i];
        }
    }
    if (current > highest)
    {
        highest = current;
    }
            std::cout << highest << std::endl;

    // for (auto i : array_int)
    // {
    //     std::cout << i << std::endl;
    // }
    return 0;
}

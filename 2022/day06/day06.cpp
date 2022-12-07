#include "../helper.cpp"

Helper h;
int main()
{
    std::vector<std::string> array_str;

    int position{};
    array_str = h.read_input_string("input.txt");

    for (int i = 3; i < array_str[0].size(); ++i)
    {
        std::set<char> test_set;
        test_set.insert(array_str[0][i - 3]);
        if (!test_set.count(array_str[0][i - 2]))
        {
            test_set.insert(array_str[0][i - 2]);
            if (!test_set.count(array_str[0][i - 1]))
            {
                test_set.insert(array_str[0][i - 1]);
                if (!test_set.count(array_str[0][i]))
                {
                    test_set.insert(array_str[0][i]);
                    position = i;
                    break;
                }
            }
        }

        position = i;
    }
    std::cout << position + 1 << std::endl;

    // for (auto i : array_str)
    // {
    //     std::cout << i<< std::endl;
    // }
    return 0;
}

#include "../helper.cpp"

Helper h;
int main()
{
    std::vector<std::string> array_str;

    int position{-1};
    array_str = h.read_input_string("input.txt");

    for (int i = 13; i < array_str[0].size(); ++i)
    {
        std::set<char> test_set;

        for (auto l = 13; l >= 0; --l)
        {
            std::cout << "l " << l << std::endl;

            if (test_set.empty() || !test_set.count(array_str[0][i - l]))
            {
                test_set.insert(array_str[0][i - l]);
            }
            else
            {
                break;
            }
            if (l == 0)
            {
                position = i;
                break;
            }
        }
        if (position > -1)
        {
            break;
        }
    }
    std::cout << position + 1 << std::endl;

    // for (auto i : array_str)
    // {
    //     std::cout << i<< std::endl;
    // }
    return 0;
}

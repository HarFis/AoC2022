#include <set>
#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<std::pair<std::string, std::string>> array_str;
    std::vector<int> array_int;
    int sum{}; // 25
    array_str = m.read_input_string_to_pair_by_length("input.txt");
    // std::pair test = m.string_to_pair_by_separator(array_str[0],' ');
    std::vector<char> doublepacks;
    for (auto &i : array_str)
    {
        std::set<char> checker;
        for (char t : i.first)
        {
            checker.insert(t);
        }
        for (char t : i.second)
        {
            if (checker.count(t))
            {
                doublepacks.emplace_back(t);
                break;
            }
        }
    }
    std::vector<int> the_ints;
    for (auto i = 0; i < doublepacks.size(); ++i)
    {
        int value;
        if ((int)doublepacks[i] > 64 && (int)doublepacks[i] < 91)
        {
            value = (int)doublepacks[i] - 65 + 27;
        }
        else
        {
            value = (int)doublepacks[i] - 96;
        }
        the_ints.emplace_back(value);
    }

    // for (auto i : array_str)
    // {
    //     std::cout << i.first << " " << i.second << std::endl;
    // }
    for (auto i : the_ints)
    {
        std::cout << i << std::endl;
        sum += i;
    }
    for (auto i : doublepacks)
    {
        std::cout << i << std::endl;
    }
    std::cout << "final sum: " << sum << std::endl;
    return 0;
}

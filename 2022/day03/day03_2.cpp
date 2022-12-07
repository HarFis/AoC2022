#include <set>
#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<std::string> array_str;
    std::vector<int> array_int;
    int sum{}; // 25
    array_str = m.read_input_string("input.txt");
    // std::pair test = m.string_to_pair_by_separator(array_str[0],' ');
    std::vector<char> doublepacks;
    int increment = 3;

    // Jump 3 rows forward
    // convert row 1 and row 2 to set 1 and set 2
    // loop through row 3 and compare if char exists in set 1 AND set 2
    // save in array
    // transform to right number -> sum
    // DONE
    for (auto j = 2; j < array_str.size(); j+=increment)
    {
        std::set<char> checker_1;
        for (char t : array_str[j - 1])
        {
            checker_1.insert(t);
        }

        std::set<char> checker_2;
        for (char s : array_str[j - 2])
        {
            checker_2.insert(s);
        }

        for (char p : array_str[j])
        {
            if(checker_1.count(p) && checker_2.count(p))
            {
                                doublepacks.emplace_back(p);
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

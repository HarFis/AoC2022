#include "../helper.cpp"

Helper m;
std::set<int> convertToSet(std::vector<int> v);
int main()
{
    std::vector<std::pair<std::string, std::string>> array_str_pair;
    std::vector<std::pair<std::vector<int>, std::vector<int>>> vector_of_vector_int;
    int sum{};
    array_str_pair = m.read_input_string_to_pair_with_separator("input.txt", ',');
    // std::pair test = m.string_to_pair_by_separator(array_str[0],',');
    for (auto &k : array_str_pair)
    {
        std::pair<int, int> tmp1 = m.string_to_int_pair_by_separator(k.first, '-');
        std::vector<int> tmp1_vec;
        for (auto t = tmp1.first; t < tmp1.second + 1; ++t)
        {
            tmp1_vec.emplace_back(t);
        }

        std::pair<int, int> tmp2 = m.string_to_int_pair_by_separator(k.second, '-');
        std::vector<int> tmp2_vec;
        for (auto f = tmp2.first; f < tmp2.second + 1; ++f)
        {
            tmp2_vec.emplace_back(f);
        }

        std::set<int> longer;
        if (tmp1_vec.size() < tmp2_vec.size())
        {
            longer = convertToSet(tmp2_vec);
            for (int o = 0; o < tmp1_vec.size(); ++o)
            {
                if (!longer.count(tmp1_vec[o]))
                {
                    break;
                }

                std::cout << "O " << o << " Size: " << tmp1_vec.size() << std::endl;
                if(o == (tmp1_vec.size()-1))
                {sum += 1;}
            }
        }
        else
        {
            longer = convertToSet(tmp1_vec);
            for (int o = 0; o < tmp2_vec.size(); ++o)
            {
                if (!longer.count(tmp2_vec[o]))
                {
                    break;
                }
                if(o == (tmp2_vec.size()-1))
                {sum += 1;}
            }
        }
    }

    // in pairs by string
    // vector of pairs of vectors (with ascending numbers)
    // if longer (1) or same (2) to set
    // loop through other with .counts
    // break as soon as first yes

    for (auto i : array_str_pair)
    {
        std::cout << i.first << std::endl;
    }
    std::cout << "Winner " << sum << std::endl;
    return 0;
}

std::set<int> convertToSet(std::vector<int> v)
{
    std::set<int> s(v.begin(), v.end());
    return s;
}
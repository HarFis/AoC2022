#include "../helper.cpp"
// std::pair<std::string, std::string> string_to_pair_by_separator(const std::string str, const char separator, const bool isSwapped);
Helper m;
int main()
{

    int sum{}; 
    std::vector<std::pair<std::string, std::string>> pairs = m.read_input_string_to_pair_with_separator("input.txt",' ');


    for (auto i : pairs)
    {
        if (i.second == "X")
        {
            // i loose
            if (i.first == "A")
            {
                i.second = "Z";
            }
            else if (i.first == "B")
            {
                i.second = "X";
            }
            else
            {
                i.second = "Y";
            }
        }
        else if (i.second == "Y")
        {
            // I draw
            if (i.first == "A")
            {
                i.second = "X";
            }
            else if (i.first == "B")
            {
                i.second = "Y";
            }
            else
            {
                i.second = "Z";
            }
        }
        else
        {
            // I win
            if (i.first == "A")
            {
                i.second = "Y";
            }
            else if (i.first == "B")
            {
                i.second = "Z";
            }
            else
            {
                i.second = "X";
            }
        }

        if (i.second == "X")
        {
            sum += 1;
        }
        else if (i.second == "Y")
        {
            sum += 2;
        }
        else
        {
            sum += 3;
        }

        if ((i.first == "A" && i.second == "X") || (i.first == "B" && i.second == "Y") || (i.first == "C" && i.second == "Z"))
        {
            // Draw
            sum += 3;
        }
        else if ((i.first == "A" && i.second == "Y" )|| (i.first == "B" && i.second == "Z" )|| (i.first == "C" && i.second == "X"))
        {
            sum += 6;
        }
        else
        {
        }
    }

    for (auto i : pairs)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    std::cout << sum << std::endl;
    return 0;
}

// std::pair<std::string, std::string> string_to_pair_by_separator(const std::string str, const char separator, const bool isSwapped)
// {
//     std::string key, val;
//     std::stringstream ss(str);
//     std::getline(ss, key, separator);
//     std::getline(ss, val);
//     std::pair<std::string, std::string> result;
//     if (isSwapped)
//         result = make_pair(val, key);
//     else
//         result = make_pair(key, val);
//     return result;
// }
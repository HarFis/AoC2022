#include "Helper.h"

std::vector<int> Helper::read_input_int(const std::string filename)
{
    std::vector<int> array_;
    std::string line;
    std::ifstream input_file;
    input_file.open(filename);
    if (!input_file.is_open())
    {
        std::cout << "ERROR opening file";
    }
    while (getline(input_file, line))
    {
        // std::cout << line << '\n';
        int write_value{-1};
        try
        {
            write_value = std::stoi(line);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        

        array_.push_back(write_value);
    }
    if (input_file.is_open())
    {
        input_file.close();
    }
    return array_;
}

std::pair<std::string, std::string> Helper::string_to_pair_by_separator(const std::string str, const char separator, const bool isSwapped = false)
{
    std::string key, val;
    std::stringstream ss(str);
    std::getline(ss, key, separator);
    std::getline(ss, val);
    std::pair<std::string, std::string> result;
    if (isSwapped)
        result = make_pair(val, key);
    else
        result = make_pair(key, val);
    return result;
}

std::vector<std::string> Helper::read_input_string(const std::string filename)
{
    std::vector<std::string> array_;
    std::string line;
    std::ifstream input_file;
    input_file.open(filename);
    if (!input_file.is_open())
    {
        std::cout << "ERROR opening file";
    }
    while (getline(input_file, line))
    {
        array_.push_back(line);
    }
    if (input_file.is_open())
    {
        input_file.close();
    }
    return array_;
}

std::vector<std::pair<std::string,std::string>> Helper::read_input_string_to_pair_with_separator(const std::string filename, const char separator)
{
    std::vector<std::pair<std::string,std::string>> array_;
    std::string line;
    std::ifstream input_file;
    input_file.open(filename);
    if (!input_file.is_open())
    {
        std::cout << "ERROR opening file";
    }
    while (getline(input_file, line))
    {
        std::pair<std::string,std::string> pairs;
        pairs = string_to_pair_by_separator(line, separator);
        array_.push_back(pairs);
    }
    if (input_file.is_open())
    {
        input_file.close();
    }
    return array_;
}

std::vector<int> Helper::comma_seperated_string_to_int_array(const std::string str)
{
    std::stringstream ss;
    ss.str(str);
    std::vector<int> result;
    while (ss.good())
    {
        std::string substr;
        getline(ss, substr, ',');
        result.push_back(std::stoi(substr));
    }
    return result;
}

std::array<int, 5> Helper::convert_multiply(const int multiply)
{
    std::array<int, 5> marray;
    marray[0] = (multiply / 10000) % 10;
    marray[1] = (multiply / 1000) % 10;
    marray[2] = (multiply / 100) % 10;
    marray[3] = (multiply / 10) % 10;
    marray[4] = multiply % 10;
    return marray;
}

std::vector<std::pair<int, int>> Helper::string_to_vector_pair(const std::string str)
{
    std::stringstream ss;
    ss.str(str);
    std::vector<std::pair<int, int>> result;
    while (ss.good())
    {
        std::string all;
        int steps;
        getline(ss, all, ',');
        std::string direction = all.substr(0, 1);
        int dic_int;
        if (direction == "R")
            dic_int = 1;
        else if (direction == "U")
            dic_int = 2;
        else if (direction == "D")
            dic_int = 3;
        else
            dic_int = 4;

        steps = std::stoi(all.substr(1));

        result.push_back(std::make_pair(dic_int, steps));
    }
    return result;
}

std::vector<int> Helper::string_to_int_array(const std::string str)
{
    std::vector<int> result;

    for (int i = 0; i < str.length(); i++)
        result.push_back(str[i] - '0');

    return result;
}

std::vector<std::pair<std::string,std::string>> Helper::read_input_string_to_pair_by_length(const std::string filename)
{
    std::vector<std::pair<std::string,std::string>> array_;
    std::string line;
    std::ifstream input_file;
    input_file.open(filename);
    if (!input_file.is_open())
    {
        std::cout << "ERROR opening file";
    }
    while (getline(input_file, line))
    {
        std::pair<std::string,std::string> pair;
        pair = create_pair_by_half(line);
        array_.push_back(pair);
    }
    if (input_file.is_open())
    {
        input_file.close();
    }
    return array_;
}

std::pair<std::string, std::string> Helper::create_pair_by_half(const std::string str)
{
std::pair<std::string,std::string> pair;
    pair.first = str.substr(0, str.length()/2);
    pair.second = str.substr(str.length()/2);
    return pair;
}

std::pair<int,int> Helper::string_to_int_pair_by_separator(const std::string str, const char separator)
{
    std::string key, val;
    std::stringstream ss(str);
    std::getline(ss, key, separator);
    std::getline(ss, val);
    std::pair<int,int> result;
    //std::cout << key << std::endl;
    result.first = std::stoi(key);
    result.second = std::stoi(val);
    return result;
}

std::vector<int> Helper::extract_int_from_string(const std::string str)
{
    std::vector<int> result;
    std::stringstream ss;
    ss << str;
    std::string temp;
    int found;
    while (!ss.eof())
    {
        ss >> temp;
        if (std::stringstream(temp) >> found)
            result.emplace_back(found);
        temp = "";
    }
    return result;
}

std::stack<std::string> Helper::extract_string_to_stack(const std::string str)
{
    std::istringstream ss(str);
    std::stack<std::string> chars;
    std::string token;
    while (std::getline(ss, token, ','))
    {

        chars.push(token);
    }
    return chars;
}

std::stack<char> Helper::extract_char_to_stack(const std::string str, const char separator)
{
    std::istringstream ss(str);
    std::stack<char> chars;
    std::string token;
    while (std::getline(ss, token, separator))
    {
        chars.push(token[0]);
    }
    return chars;
}

std::vector<int> Helper::convert_str_to_int_array(const std::string str)
{
    std::vector<int> vector;
    for (int i = 0; i < str.size(); ++i)
    {
        vector.emplace_back((int)str[i] - 48);
    }
    return vector;
}

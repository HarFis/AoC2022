#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<std::string> array_str;
    std::vector<int> array_int;
    int sum{};
    array_str = m.read_input_string("test.txt");
    std::pair test = m.string_to_pair_by_separator(array_str[0],' ');
    for (auto i : array_int)
    {
        std::cout << i<< std::endl;
    }
    return 0;
}

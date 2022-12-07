#include <stack>
#include <iostream>

#include "../helper.cpp"
#include "../Helper.h"

Helper h;

int main()
{
    std::vector<std::stack<std::string>> warehouse;
    std::vector<std::vector<int>> commands;
    // read in initial stacks
    // read in commands
    // do execute commands

    std::vector<std::string> rows_of_stack;
    rows_of_stack = h.read_input_string("input1.txt");
    for (auto &m : rows_of_stack)
    {
        warehouse.emplace_back(h.extract_string_to_stack(m));
    }
    for (auto i : warehouse)
    {
        std::cout << i.size() << " ";
    }

    std::vector<std::string> rows_of_commands;
    rows_of_commands = h.read_input_string("input2.txt");
    for (auto &m : rows_of_commands)
    {
        commands.emplace_back(h.extract_int_from_string(m));
    }

    int counter{};
    for (auto &k : commands)
    {
        counter += 1;
        std::cout << counter << std::endl;
        std::vector<std::string> crate_mover;
        for (int i = 0; i < k[0]; ++i)
        {
            std::string value = warehouse[k[1] - 1].top();
            crate_mover.emplace_back(value);
            warehouse[k[1] - 1].pop();
        }
        for (int i = k[0]-1; i >= 0; --i)
        {
                    warehouse[k[2] - 1].push(crate_mover[i]);
        }
    }

    // std::vector<std::string> array_str;
    // std::vector<int> array_int;
    // int sum{};
    // array_str = m.read_input_string("test.txt");
    // std::pair test = m.string_to_pair_by_separator(array_str[0],' ');

    for (auto i : warehouse)
    {
        std::cout << i.top();
    }
    std::cout << std::endl;
    return 0;
}
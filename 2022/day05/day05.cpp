#include "../helper.cpp"

Helper h;
int main()
{
    // read in initial stacks (copy paste from task) - input1
    // read in commands (extract all int into a vector) - input2
    // do execute commands
    std::vector<std::stack<char>> warehouse;
    std::vector<std::vector<int>> commands;

    std::vector<std::string> rows_of_stack;
    rows_of_stack = h.read_input_string("input1.txt");
    for (auto &m : rows_of_stack)
    {
        warehouse.emplace_back(h.extract_char_to_stack(m, ','));
    }

    std::vector<std::string> rows_of_commands;
    rows_of_commands = h.read_input_string("input2.txt");
    for (auto &m : rows_of_commands)
    {
        commands.emplace_back(h.extract_int_from_string(m));
    }

    for (auto &k : commands)
    {
        for (int i = 0; i < k[0]; ++i)
        {
            char value = warehouse[k[1] - 1].top();
            warehouse[k[2] - 1].push(value);
            warehouse[k[1] - 1].pop();
        }
    }
    for (auto i : warehouse)
    {
        std::cout << i.top();
    }
    std::cout << std::endl;
    return 0;
}

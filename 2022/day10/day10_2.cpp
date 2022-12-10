#include <queue>
#include "../helper.cpp"

Helper h;
int main()
{
    // read in as pair (noops with dummy int)
    // loop through
    // run instructions - add nr. in queue
    // position of sprite and then write right char

    std::vector<std::pair<std::string, int>> commands;
    std::queue<int> queuing_commands;
    int signal_sum{1};
    commands = h.read_input_string_to_special_pair_str_int_with_separator("input.txt", ' ');
    int max_cycles{300};
    int cycle{1};
    std::vector<char> matrix;
    for (auto c = 0; c < 400; ++c)
    {
        // during

        std::cout << "D cycle: " << cycle << " signal sum: " << signal_sum << std::endl;
        // position of sprite
        if (signal_sum < ((cycle - 1) % 40 + 2) && signal_sum > ((cycle - 1) % 40 - 2))
        {
            matrix.emplace_back('#');
        }
        else
        {
            matrix.emplace_back('.');
        }
        try
        {
            if (commands.at(c).first[0] == 'a')
            {
                queuing_commands.push(commands.at(c).second);
                cycle += 1;
                std::cout << "A cycle: " << cycle << " signal sum: " << signal_sum << std::endl;
                // position of sprite
                if (signal_sum < (((cycle - 1) % 40) + 2) && signal_sum > (((cycle - 1) % 40) - 2))
                {
                    matrix.emplace_back('#');
                }
                else
                {
                    matrix.emplace_back('.');
                }

                cycle += 1;
            }
            else
            {
                cycle += 1;
            }
        }
        catch (const std::exception &e)
        {
            cycle += 1;
        }

        // after
        if (!queuing_commands.empty())
        {
            signal_sum += queuing_commands.front();
            queuing_commands.pop();
            if (!queuing_commands.empty())
                std::cout << "next in queue: " << queuing_commands.front() << std::endl;
        }

        if (cycle == max_cycles)
        {
            break;
        }
        for (auto m : matrix)
        {
            std::cout << m;
        }
        std::cout << std::endl;
    }
    // std::cout << "the final sum: " << sum << std::endl;

    for (int m = 1; m < matrix.size(); ++m)
    {
        // workaround for m%40 -> 0
        std::cout << matrix[m - 1];
        if (m % 40 == 0)
        {
            std::cout << "i " << std::endl;
        }
    }
    return 0;
}

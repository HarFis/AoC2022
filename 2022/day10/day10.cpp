#include <queue>
#include "../helper.cpp"

Helper h;
int main()
{
    // read in as pair (noops with dummy int)
    // loop through
    // run instructions - add nr. in queue
    // before and after print
    // sum of it

    std::vector<std::pair<std::string, int>> commands;
    std::queue<int> queuing_commands;
    int signal_sum{1};
    int sum{};
    commands = h.read_input_string_to_special_pair_str_int_with_separator("input.txt", ' ');
    int max_cycles{300};
    int cycle{1};
    for (auto c = 0; c < 400; ++c)
    {
        // during
        std::cout << "cycle: " << cycle << " signal sum: " << signal_sum << " signal strength: " << cycle * signal_sum << std::endl;
        try
        {
            if (commands.at(c).first[0] == 'a')
            {
                queuing_commands.push(commands.at(c).second);
                cycle += 1;
                if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
                {
                    std::cout << "during cycle: " << cycle << " signal sum: " << signal_sum << " signal strength: " << cycle * signal_sum << std::endl;
                    sum += (cycle * signal_sum);
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
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
        {
            std::cout << "during cycle: " << cycle << " signal sum: " << signal_sum << " signal strength: " << cycle * signal_sum << std::endl;
            sum += (cycle * signal_sum);
        }
        if (cycle == max_cycles)
        {
            break;
        }
    }
    std::cout << "the final sum: " << sum << std::endl;
    return 0;
}
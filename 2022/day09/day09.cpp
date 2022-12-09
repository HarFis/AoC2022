#include "../helper.cpp"

Helper h;
bool tail_has_to_move(std::pair<int, int> tail_pos, std::pair<int, int> head_pos);

int main()
{
    std::vector<std::pair<std::string, int>> array_str;
    std::vector<int> array_int;
    int tail_moves{};
    array_str = h.read_input_string_to_pair_str_int_with_separator("test.txt", ' ');
    // .first = x pos | .second = y pos
    std::pair<int, int> head_pos{};
    std::pair<int, int> tail_pos{};

    for (auto i : array_str)
    {
        // right = x pos ++
        if (i.first == "R")
        {
            //loop down into single steps
            head_pos.first += i.second;
        }
        // up = y pos ++
        else if (i.first == "U")
        {
            head_pos.second += i.second;
        }
        // left = x pos --
        else if (i.first == "L")
        {
            head_pos.first -= i.second;
        }
        // down = y pos --
        else
        {
            head_pos.second -= i.second;
        }

        std::cout << "Current position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
        std::cout << "Move it: " << tail_has_to_move(tail_pos, head_pos) << std::endl;
    }

    for (auto i : array_str)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }
    return 0;
}

bool tail_has_to_move(std::pair<int, int> tail_pos, std::pair<int, int> head_pos)
{
    bool has_to_move{false};
    int x_delta = head_pos.first - tail_pos.first;
    int y_delta = head_pos.second - tail_pos.second;
    if (std::abs(x_delta) > 1 || std::abs(y_delta) > 1)
    {
        has_to_move = true;
    }
    return has_to_move;
}
#include "../helper.cpp"

Helper h;
bool tail_has_to_move(std::pair<int, int> tail_pos, std::pair<int, int> head_pos);
std::pair<int, int> update_tail_pos(std::pair<int, int> tail_pos, std::pair<int, int> head_pos);
void print_pos(const std::pair<int, int> t, const std::pair<int, int> h);

int main()
{
    /*
    Read input as pair - director + steps
    Store head and tail coordinates as pair in each
    Check at every step if movement of tail necessary
    Move tail if necessary according to the rules (sideways, up-/downwards or diagonal)
    store position in set (avoid duplicate)    
    */
    std::vector<std::pair<std::string, int>> array_str;
    std::vector<int> array_int;
    int tail_moves{};
    array_str = h.read_input_string_to_pair_str_int_with_separator("input.txt", ' ');
    // .first = x pos | .second = y pos
    std::set<std::pair<int, int>> collection;
    std::pair<int, int> head_pos{};
    std::pair<int, int> tail_pos{};
    collection.emplace(tail_pos);
    for (auto i : array_str)
    {
        // right = x pos ++
        if (i.first == "R")
        {
            // loop down into single steps
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.first += 1;
                // std::cout << "R Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
                //  std::cout << "R Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;

                if (tail_has_to_move(tail_pos, head_pos))
                {
                    tail_pos = update_tail_pos(tail_pos, head_pos);
                    // std::cout << "R New tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
                    tail_moves += 1;
                }
                // std::cout << "R Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
                // print_pos(tail_pos, head_pos);
                collection.emplace(tail_pos);
            }
        }
        // up = y pos ++
        else if (i.first == "U")
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.second += 1;
                // std::cout << "U Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
                // std::cout << "U Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;

                if (tail_has_to_move(tail_pos, head_pos))
                {
                    tail_pos = update_tail_pos(tail_pos, head_pos);
                    // std::cout << "U New tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
                    tail_moves += 1;
                }
                // print_pos(tail_pos, head_pos);
                collection.emplace(tail_pos);
            }
        }
        // left = x pos --
        else if (i.first == "L")
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.first -= 1;
                // std::cout << "L Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
                // std::cout << "L Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;

                if (tail_has_to_move(tail_pos, head_pos))
                {
                    tail_pos = update_tail_pos(tail_pos, head_pos);
                    std::cout << "L New tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
                    tail_moves += 1;
                }
                // print_pos(tail_pos, head_pos);
                collection.emplace(tail_pos);
            }
        }
        // down = y pos --
        else
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.second -= 1;
                // std::cout << "D Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
                // std::cout << "D Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;

                if (tail_has_to_move(tail_pos, head_pos))
                {
                    tail_pos = update_tail_pos(tail_pos, head_pos);
                    // std::cout << "D New tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
                    tail_moves += 1;
                }
                // print_pos(tail_pos, head_pos);
                collection.emplace(tail_pos);
            }
        }
    }
    std::cout << "Final head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
    std::cout << "Final tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
    std::cout << "Tail moves: " << tail_moves << std::endl;
    std::cout << "Positions: " << collection.size() << std::endl;

    // for (auto i : array_str)
    // {
    //     std::cout << i.first << " " << i.second << std::endl;
    // }
    return 0;
}

// -----------------------------------------------------------
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

std::pair<int, int> update_tail_pos(const std::pair<int, int> tail_pos, const std::pair<int, int> head_pos)
{
    std::pair<int, int> new_pos_tail{tail_pos};
    if (tail_pos.second == head_pos.second)
    {
        std::cout << "move on x axis" << std::endl;
        if (tail_pos.first > head_pos.first)
        {
            new_pos_tail.first = (tail_pos.first - 1);
        }
        else
        {
            new_pos_tail.first = (tail_pos.first + 1);
        }
    }
    else if (tail_pos.first == head_pos.first)
    {
        std::cout << "move on y axis" << std::endl;
        if (tail_pos.second > head_pos.second)
        {
            new_pos_tail.second = (tail_pos.second - 1);
        }
        else
        {
            new_pos_tail.second = (tail_pos.second + 1);
        }
    }
    else
    {
        std::cout << "diagonal move" << std::endl;
        int sc_value = (head_pos.first - tail_pos.first) + (head_pos.second - tail_pos.second);
        switch (sc_value)
        {
        case 3:
            new_pos_tail.first = (tail_pos.first + 1);
            new_pos_tail.second = (tail_pos.second + 1);
            break;
        case (-3):
            new_pos_tail.first = (tail_pos.first - 1);
            new_pos_tail.second = (tail_pos.second - 1);
            break;
        case (1):
        case (-1):
            if ((head_pos.first - tail_pos.first) >= 1)
            {
                new_pos_tail.first = (tail_pos.first + 1);
                new_pos_tail.second = (tail_pos.second - 1);
            }
            else
            {
                new_pos_tail.first = (tail_pos.first - 1);
                new_pos_tail.second = (tail_pos.second + 1);
            }
            break;
        default:
            std::cout << "Something wrong in the neighbourhoud " << sc_value << std::endl;
            break;
        }
    }
    std::cout << "New tail pos before return: " << new_pos_tail.first << " " << new_pos_tail.second << std::endl;
    return new_pos_tail;
}

void print_pos(const std::pair<int, int> t, const std::pair<int, int> h)
{
    for (int i = 0; i < 20; ++i)
    {
        for (int l = 0; l < 20; ++l)
        {
            if (l == t.first + 10 && i == t.second + 10)
            {
                std::cout << "t";
            }
            else if (l == h.first + 10 && i == h.second + 10)
            {
                std::cout << "h";
            }
            else
            {
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << " ------------- " << std::endl;
}
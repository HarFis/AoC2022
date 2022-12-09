#include "../helper.cpp"

Helper h;
bool tail_has_to_move(std::pair<int, int> tail_pos, std::pair<int, int> head_pos);
std::pair<int, int> update_tail_pos(std::pair<int, int> tail_pos, std::pair<int, int> head_pos);
void print_pos(const std::pair<int, int> t, const std::pair<int, int> h);

int main()
{
    std::vector<std::pair<std::string, int>> array_str;
    std::vector<int> array_int;
    array_str = h.read_input_string_to_pair_str_int_with_separator("input.txt", ' ');
    // .first = x pos | .second = y pos
    std::set<std::pair<int, int>> collection;
    std::vector<std::pair<int, int>> tails;
    int nr_of_tails{9};
    std::pair<int, int> head_pos{};
    std::pair<int, int> tail_pos{};
    for (auto f = 0; f < nr_of_tails; ++f)
    {
        tails.emplace_back(tail_pos);
    }

    collection.emplace(tails.back());
    for (auto i : array_str)
    {
        // right = x pos ++
        if (i.first == "R")
        {
            // loop down into single steps
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.first += 1;
                std::cout << "R Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;

                if (tail_has_to_move(tails.front(), head_pos))
                {
                    tails.front() = update_tail_pos(tails.front(), head_pos);
                }
                for (auto m = 1; m < tails.size(); ++m)
                {
                    if (tail_has_to_move(tails[m], tails[m - 1]))
                    {
                        tails[m] = update_tail_pos(tails[m], tails[m - 1]);
                    }
                }
                
                collection.emplace(tails.back());
            }
        }
        // up = y pos ++
        else if (i.first == "U")
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.second += 1;
                std::cout << "U Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;

                if (tail_has_to_move(tails.front(), head_pos))
                {
                    tails.front() = update_tail_pos(tails.front(), head_pos);
                }
                for (auto m = 1; m < tails.size(); ++m)
                {
                    std::cout << "Up tail " << m + 1 << " position: x " << tails[m].first << " y: " << tails[m].second << std::endl;
                    if (tail_has_to_move(tails[m], tails[m - 1]))
                    {
                        tails[m] = update_tail_pos(tails[m], tails[m - 1]);
                    }
                }
                collection.emplace(tails.back());
            }
        }
        // left = x pos --
        else if (i.first == "L")
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.first -= 1;
                std::cout << "L Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;

                if (tail_has_to_move(tails.front(), head_pos))
                {
                    tails.front() = update_tail_pos(tails.front(), head_pos);
                }
                for (auto m = 1; m < tails.size(); ++m)
                {
                    if (tail_has_to_move(tails[m], tails[m - 1]))
                    {
                        tails[m] = update_tail_pos(tails[m], tails[m - 1]);
                    }
                }
                collection.emplace(tails.back());
            }
        }
        // down = y pos --
        else
        {
            for (auto p = 0; p < i.second; ++p)
            {
                head_pos.second -= 1;
                std::cout << "D Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;

                if (tail_has_to_move(tails.front(), head_pos))
                {
                    tails.front() = update_tail_pos(tails.front(), head_pos);
                }
                for (auto m = 1; m < tails.size(); ++m)
                {
                    if (tail_has_to_move(tails[m], tails[m - 1]))
                    {
                        tails[m] = update_tail_pos(tails[m], tails[m - 1]);
                    }
                }
                collection.emplace(tails.back());
            }
        }
        for (auto i : tails)
        {
            std::cout << "Current tail positions: x " << i.first << " y: " << i.second << std::endl;
        }
    }
    std::cout << "Final head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
    for (auto i : tails)
    {
        std::cout << "Final tail position: x " << i.first << " y: " << i.second << std::endl;
    }

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
        //std::cout << "move on x axis" << std::endl;
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
        //std::cout << "move on y axis" << std::endl;
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
       // std::cout << "diagonal move" << std::endl;
        int sc_value = (head_pos.first - tail_pos.first) + (head_pos.second - tail_pos.second);
       std::cout << "in switch case " << sc_value <<std::endl;
        switch (sc_value)
        {

        case 0:
            if ((head_pos.first - tail_pos.first) >0)
            {
                new_pos_tail.first = (tail_pos.first + 1);
                std::cout << tail_pos.second << std::endl;
                
                new_pos_tail.second = (tail_pos.second - 1);
                std::cout << new_pos_tail.second << std::endl;
            }
            else
            {
                std::cout << "out here" << std::endl;
                new_pos_tail.first = (tail_pos.first - 1);
                new_pos_tail.second = (tail_pos.second + 1);
            }
            break;
        case 4:
        case 3:
            new_pos_tail.first = (tail_pos.first + 1);
            new_pos_tail.second = (tail_pos.second + 1);
            break;
        case (-4):
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
            std::cout << "Current head position: x " << head_pos.first << " y: " << head_pos.second << std::endl;
            std::cout << "Current tail position: x " << tail_pos.first << " y: " << tail_pos.second << std::endl;
            exit(1);
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
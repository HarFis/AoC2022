#include <queue>
#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<std::string> array_str;

    array_str = m.read_input_string("input.txt");
    std::vector<std::vector<int>> array_with_int_arrays;
    int most_scenic_tree_score{};

    for (auto i : array_str)
    {
        array_with_int_arrays.emplace_back(m.convert_str_to_int_array(i));
    }

    int row_pos;
    int column_pos;
    int row_length = array_with_int_arrays[0].size();
    int column_length = array_with_int_arrays.size();
    for (row_pos = 1; row_pos < row_length - 1; ++row_pos)
        for (column_pos = 1; column_pos < column_length - 1; ++column_pos)
        {
            int current = array_with_int_arrays[column_pos][row_pos];
            int current_scenic_score{};
            int up_map{};
            int right_map{};
            int down_map{};
            int left_map{};

            // into function
            for (int up = column_pos - 1; up >= 0; --up)
            {
                if (array_with_int_arrays[up][row_pos] < current)
                {
                    up_map += 1;
                }
                else
                {
                    up_map += 1;
                    break;
                }
            }

            for (int right = row_pos + 1; right < row_length; ++right)
            {
                if (array_with_int_arrays[column_pos][right] < current)
                {
                    right_map += 1;
                }
                else
                {
                    right_map += 1;
                    break;
                }
            }

            for (int down = column_pos + 1; down < column_length; ++down)
            {
                if (array_with_int_arrays[down][row_pos] < current)
                {
                    down_map += 1;
                }
                else
                {
                    down_map += 1;
                    break;
                }
            }

            for (int left = row_pos - 1; left >= 0; --left)
            {
                if (array_with_int_arrays[column_pos][left] < current)
                {
                    left_map += 1;
                }
                else
                {
                    left_map += 1;
                    break;
                }
            }
            current_scenic_score = up_map * right_map * down_map * left_map;
            //std::cout << "scenic " << current_scenic_score << " at row nr: " << column_pos << " column nr: " << row_pos << " value " << current << std::endl;
            most_scenic_tree_score = std::max(most_scenic_tree_score, current_scenic_score);
        }

    // for (auto i : array_with_int_arrays)
    // {
    //     for (auto m : i)
    //     {
    //         // std::cout << m << std::endl;
    //     }
    // }
    std::cout << "scenic score: " << most_scenic_tree_score << std::endl;
    return 0;
}

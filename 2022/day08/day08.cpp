#include <queue>
#include "../helper.cpp"

Helper m;
int main()
{
    // vector of (int) vectors (kind of coordination system and matrix)
    // count sourrounding trees
    // loop throug all inner trees
    // adding all trees up, right, down, left to priority queue
    // if any priority queue top is less than current tree's height = visible

    std::vector<std::string> array_str;

    array_str = m.read_input_string("input.txt");
    std::vector<std::vector<int>> array_with_int_arrays;
    int sum_visible{};

    for (auto i : array_str)
    {
        array_with_int_arrays.emplace_back(m.convert_str_to_int_array(i));
    }
    sum_visible = (array_with_int_arrays.size() * 2) + (array_with_int_arrays[0].size() * 2) - 4;
    std::cout << "Trees around: " << sum_visible << std::endl;

    int row_pos;
    int column_pos;
    int row_length = array_with_int_arrays[0].size();
    int column_length = array_with_int_arrays.size();
    for (row_pos = 1; row_pos < row_length - 1; ++row_pos)
        for (column_pos = 1; column_pos < column_length - 1; ++column_pos)
        {
            int current = array_with_int_arrays[column_pos][row_pos];
            std::priority_queue<int> up_map;
            std::priority_queue<int> right_map;
            std::priority_queue<int> down_map;
            std::priority_queue<int> left_map;

            // into function
            for (int up = column_pos - 1; up >= 0; --up)
            {
                up_map.push(array_with_int_arrays[up][row_pos]);
            }

            for (int right = row_pos + 1; right < row_length; ++right)
            {
                right_map.push(array_with_int_arrays[column_pos][right]);
            }

            for (int down = column_pos + 1; down < column_length; ++down)
            {
                down_map.push(array_with_int_arrays[down][row_pos]);
            }

            for (int left = row_pos - 1; left >= 0; --left)
            {
                left_map.push(array_with_int_arrays[column_pos][left]);
            }

            if (up_map.top() < current || right_map.top() < current || down_map.top() < current || left_map.top() < current)
            {
                sum_visible += 1;
                // std::cout << "Sum visible " << sum_visible << " at row nr: " << column_pos << " column nr: " << row_pos << " value " << current << std::endl;
            }
        }

    // for (auto i : array_with_int_arrays)
    // {
    //     for (auto m : i)
    //     {
    //         // std::cout << m << std::endl;
    //     }
    // }
    std::cout << "Number of visible trees: " << sum_visible << std::endl;
    return 0;
}

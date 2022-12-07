#include <ctype.h>
#include "../helper.cpp"

Helper m;
int main()
{
    std::vector<std::string> array_str;
    std::map<std::string, int> folder_size;
    array_str = m.read_input_string("input.txt");
    std::map<std::string, std::vector<std::string>> subfolders;
    // std::pair test = m.string_to_pair_by_separator(array_str[0],' ');
    std::stack<std::string> directory_stack;
    std::string current_folder;
    int individualizer{1};
    int count{};
    std::cout << "array str: " << array_str.size() << std::endl;
    for (auto c : array_str)
    {
        if (c[0] == '$')
        {
            if (!(c[2] == 'l') && !(c[5] == '.'))
            {
                current_folder = c.erase(0, 5);
                if (folder_size.count(current_folder))
                {
                    std::cout << "Something is fishy with " << current_folder << std::endl;
                    current_folder = current_folder + std::to_string(individualizer);
                    ++individualizer;
                }

                directory_stack.push(current_folder);
            }
            else if (c[5] == '.')
            {
                int subfolder_size = folder_size[directory_stack.top()];
                std::cout << directory_stack.top() << ": " << subfolder_size << std::endl;
                directory_stack.pop();
                folder_size[directory_stack.top()] += subfolder_size;
                count += 1;
            }
        }
        else if (isdigit(c.at(0)))
        {
            // std::cout << current_folder << std::endl;
            std::pair<std::string, std::string> file;
            file = m.string_to_pair_by_separator(c, ' ');
            // std::cout << std::stoi(file.first) << " - " << file.second << std::endl;
            folder_size[current_folder] += std::stoi(file.first);
        }
    }
    std::cout << "before: " << folder_size[directory_stack.top()] << std::endl;
    while (directory_stack.size() > 1)
    {
        std::cout << "stack size: " << directory_stack.size() << " " << directory_stack.top() << " bites: " << folder_size[directory_stack.top()] << std::endl;
        int subfolder_size = folder_size[directory_stack.top()];
        directory_stack.pop();
        std::cout << folder_size[directory_stack.top()] << std::endl;
        folder_size[directory_stack.top()] += subfolder_size;
        std::cout << folder_size[directory_stack.top()] << std::endl;
    }
    // Part 1
    int sum{};
    // Part 2
    int total_space = 70000000;
    int min_space = 30000000;
    int root = folder_size["/"];
    std::cout << "/ " << root << std::endl;
    int delta = total_space - root;
    int needed = min_space - delta;
    std::cout << "needed " << needed << std::endl;
    int wanted{min_space};
    for (auto &i : folder_size)
    {
        //std::cout << i.first << " " << i.second << std::endl;
        if (i.second < 100000)
        {
            // std::cout << i.first << " " << i.second << std::endl;
            sum += i.second;
        }
        if(i.second >= needed)
        {
            wanted = std::min(wanted, i.second);
        }

    }
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Smallest folder: " << wanted << std::endl;
    return 0;
}

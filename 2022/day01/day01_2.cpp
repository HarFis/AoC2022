#include "../helper.cpp"
#include <list>
#include <functional>

Helper m;
int main()
{
    std::vector<int> array_int;
    int highest{}; // 25
    int current{};
    std::list<int> top_list;
    array_int = m.read_input_int("input.txt");
    for (auto i = 0; i < array_int.size(); ++i)
    {
        if (array_int[i] == -1)
        {
            top_list.emplace_back(current);
            current = 0;
        }
        else
        {
            current+=array_int[i];
        }
    }
    top_list.emplace_back(current);
    top_list.sort(std::greater<int>());


    for(int i = 0; i<3;++i)
    {
        highest+=top_list.front();
        top_list.pop_front();
    }
    

     std::cout << highest << std::endl;

    // for (auto i : top_list)
    // {
    //     std::cout << i << std::endl;
    // }
    return 0;
}

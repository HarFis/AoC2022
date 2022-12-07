#ifndef HELPER_H
#define HELPER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <set>
#include <stack>
#include <map>

class Helper {
 public:
    std::vector<int> read_input_int(const std::string filename);
    std::vector<std::string> read_input_string(const std::string filename);
    std::vector<int> comma_seperated_string_to_int_array(const std::string str);
    std::array<int, 5> convert_multiply(const int multiply);
    std::vector<std::pair<int, int> > string_to_vector_pair(const std::string str);
    std::vector<int> string_to_int_array(const std::string str);
    std::pair<std::string, std::string> string_to_pair_by_separator(const std::string str, const char separator, const bool isSwapped);
    std::pair<int,int> string_to_int_pair_by_separator(const std::string str, const char separator);
    std::vector<std::pair<std::string,std::string>> read_input_string_to_pair_with_separator(const std::string filename, const char separator);
    std::vector<std::pair<std::string,std::string>> read_input_string_to_pair_by_length(const std::string filename);
    std::pair<std::string, std::string> create_pair_by_half(const std::string str);
    std::vector<int> extract_int_from_string(std::string str);
    std::stack<std::string> extract_string_to_stack(const std::string str);
    std::stack<char> extract_char_to_stack(const std::string str, const char separator);
    std::vector<int> convert_str_to_int_array(const std::string str);
};
// NO "Helper::" IN FRONT OF FUNCTIONS

#endif
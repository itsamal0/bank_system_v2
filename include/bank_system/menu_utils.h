#pragma once
#include <vector>
#include <string>

namespace menu_utils {

    void showMenu(const std::string& title, const std::vector<std::string>& options);
    int readValidChoice(int initialChoice, int minValue, int maxValue);
    int readMenuChoice(int minValue, int maxValue);

}

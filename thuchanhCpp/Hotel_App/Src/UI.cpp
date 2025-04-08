#include "UI.hpp"
#include <iostream>

int UI::getUserChoice(const std::string& prompt) {
    int choice;
    std::cout << prompt;
    std::cin >> choice;
    return choice;
}

void UI::showMessage(const std::string& message) {
    std::cout << message << std::endl;
}

std::string UI::getInputString(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}

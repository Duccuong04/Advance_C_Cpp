#ifndef MENUITEM_HPP
#define MENUITEM_HPP

#include <functional>
#include <string>

class MenuItem {
public:
    MenuItem(int choice, const std::string& description, std::function<void()> action)
        : choice_(choice), description_(description), action_(action) {}

    int getChoice() const { return choice_; }
    std::string getDescription() const { return description_; }
    void executeAction() const { action_(); }

private:
    int choice_;
    std::string description_;
    std::function<void()> action_;
};

#endif // MENUITEM_HPP

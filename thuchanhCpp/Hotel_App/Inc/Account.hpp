#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include <vector>

class Account {
private:
    std::string username;  // Tên tài khoản
    std::string password;  // Mật khẩu

public:
    // Constructor mặc định và constructor có tham số
    Account();
    Account(const std::string& username, const std::string& password);

    // Getter và Setter cho các thuộc tính
    std::string getUsername() const;
    std::string getPassword() const;

    void setPassword(const std::string& password);

    // Kiểm tra nếu tài khoản đã tồn tại trong danh sách
    static bool accountExists(const std::vector<Account>& accountList, const std::string& username);

    // Phương thức static để đăng ký và đăng nhập
    static bool registerAccount(std::vector<Account>& accountList, const std::string& username, const std::string& password);
    static bool login(const std::vector<Account>& accountList, const std::string& username, const std::string& password);
};

extern std::vector<Account> accountList;

#endif // ACCOUNT_HPP

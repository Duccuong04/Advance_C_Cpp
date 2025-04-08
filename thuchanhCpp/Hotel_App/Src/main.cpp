#include "Account.hpp"
#include "Manager.hpp"
#include "EmployeeManager.hpp"
#include <iostream>
#include <vector>

int main() {

    // EmployeeManager employeeManager;

    // // Thêm nhân viên mới
    // employeeManager.addEmployee(accountList, "Trung", "123456789", "Tạp vụ");
    // employeeManager.addEmployee(accountList, "Thái", "567891237", "Bảo vệ");
    // employeeManager.addEmployee(accountList, "Sơn", "123897519", "Đầu bếp");
    // employeeManager.addEmployee(accountList, "Nam", "987654321", "Lễ Tân");

    // // Hiển thị danh sách nhân viên
    // employeeManager.listEmployees();

    // // Sửa thông tin nhân viên theo tên
    // employeeManager.editEmployeeByName("Trung", "Trung Nguyen", "Quản lý Tạp vụ");

    // // Xóa nhân viên theo ID (số điện thoại)
    // employeeManager.deleteEmployeeById("567891237");

    // // Hiển thị lại danh sách nhân viên
    // employeeManager.listEmployees();


    // Thêm tài khoản mẫu để kiểm tra
    Account adminAccount("admin", "123456");  // Tài khoản admin
    Account employeeAccount("user", "123456"); // Tài khoản người dùng
    accountList.push_back(adminAccount);
    accountList.push_back(employeeAccount);

    std::string account, password;

    std::cout << "\n---- Thông tin đăng nhập ----" << std::endl;
    
    // Nhập tài khoản (có thể là số điện thoại hoặc account)
    std::cout << "Nhập tài khoản (account/sđt): ";
    std::cin >> account;

    // Nhập mật khẩu
    std::cout << "Nhập mật khẩu: ";
    std::cin >> password;

    // Kiểm tra đăng nhập
    if (Account::login(accountList, account, password)) {
        std::cout << "Đăng nhập thành công!" << std::endl;

        // Kiểm tra nếu tài khoản là "admin"
        if (account == "admin") {
            std::cout << "Xin chào Quản lý!" << std::endl;
            Manager manager;
            manager.showManagementMenu();  // Hiển thị menu quản lý
        } else {
            std::cout << "Xin chào người dùng!" << std::endl;
            // Gọi menu người dùng (nếu cần thêm chức năng cho người dùng bình thường)
        }

    } else {
        std::cout << "Đăng nhập thất bại! Tài khoản hoặc mật khẩu không đúng." << std::endl;
    }

    return 0;
}

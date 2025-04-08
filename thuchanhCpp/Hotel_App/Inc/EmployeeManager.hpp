#ifndef EMPLOYEEMANAGER_HPP
#define EMPLOYEEMANAGER_HPP

#include "Employee.hpp"
#include "Account.hpp"
#include <vector>
#include <string>
#include "EmployeeManager.hpp"

class EmployeeManager {
public:
    // Thêm nhân viên mới với ID tự động
    void addEmployee(std::vector<Account>& accountList, const std::string& name, const std::string& phoneNumber, const std::string& position);

    // Sửa thông tin nhân viên dựa theo ID
    void editEmployeeById(const std::string& id, const std::string& newName, const std::string& newPosition);
    
    // Xóa nhân viên dựa trên ID
    void deleteEmployeeById(const std::string& id);
    
    // Set ca làm việc cho nhân viên
    void setWorkShift(const std::string& id, const std::string& shift);
    
    // Xem danh sách thông tin của tất cả nhân viên
    void listEmployees() const;

private:
    std::vector<Employee> employees_;
    int employeeCounter_ = 0;  // Biến đếm số lượng nhân viên để tạo ID tự động

    // Tạo ID tự động cho nhân viên mới
    std::string generateEmployeeId(const std::string& position);
    
    // Tìm nhân viên theo tên
    Employee* findEmployeeById(const std::string& id);
};

#endif // EMPLOYEEMANAGER_HPP

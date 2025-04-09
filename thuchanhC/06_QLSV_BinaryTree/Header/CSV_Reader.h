/***************************************************************************
 * @file    CSV_Reader.h
 * @brief   Đọc file CSV đã tạo sẵn đồng thời xây dựng danh sách liên kết
 * @details Đọc các thông tin tên, tuổi, địa chỉ và số điện thoại lưu vào struct User
 * @version 1.0
 * @date    2025-04-09
 * @author  Cuong Nguyen
 ***************************************************************************/
#ifndef CSV_Reader_H
#define CSV_Reader_H

#include "../Header/User_List.h"
#define DATABASE_PATH "data/infor.csv"



// Khai báo struct lưu các cột thông tin đọc được từ file infor.csv
typedef struct 
{
    char *name;
    int age;
    char *addr;
    char *phone;
} User;

// Đọc CSV và đưa dữ liệu name, phone vào danh sách liên kết
void readCSV(const char *file_name, Node **nameList, Node **phoneList);

// Giải phóng bộ nhớ đã cấp phát động
void free_user(User *user);

#endif // CSV_Reader_H


/***************************************************************************
 * @file    CSV_Reader.h
 * @brief   Đọc file CSV đã tạo sẵn đồng thời xây dựng danh sách liên kết
 * @details Đọc các thông tin tên, tuổi, địa chỉ và số điện thoại lưu vào struct User
 * @version 1.0
 * @date    2025-04-09
 * @author  Cuong Nguyen
 ***************************************************************************/
#ifndef CSV_READER_H
#define CSV_READER_H

#include "User_List.h"

void readCSV(const char *filename, Node **nameList, Node **phoneList);

#endif

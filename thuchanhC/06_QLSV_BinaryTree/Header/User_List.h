/***************************************************************************
 * @file    User_List.h
 * @brief   Xây dựng danh sách liên kết
 * @details Xây dựng danh sách liên kết Tên và Số điện thoại, sắp xếp theo thứ tự
 * @version 1.0
 * @date    2025-04-09
 * @author  Cuong Nguyen
 ***************************************************************************/
#ifndef USER_LIST_H
#define USER_LIST_H

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

// Thêm node vào danh sách liên kết
void add_node(Node **head, const char *data);

// In danh sách
void print_list(Node *head, const char *label);

// Giải phóng bộ nhớ
void free_list(Node *head);

#endif

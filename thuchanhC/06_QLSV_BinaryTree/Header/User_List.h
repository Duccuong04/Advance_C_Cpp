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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node* create_node(const char *data);
void add_sorted(Node **head, const char *data);
void print_list(Node *head);
void free_list(Node *head);

#endif
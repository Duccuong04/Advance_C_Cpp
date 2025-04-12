/***************************************************************************
 * @file    CSV_Reader.h
 * @brief   Xây dựng Binary Search Tree
 * @details Xây dựng BST để tìm kiếm
 * @version 1.0
 * @date    2025-04-12
 * @author  Cuong Nguyen
 ***************************************************************************/
// === BST.h ===
#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cấu trúc cúa BST
typedef struct BSTNode {
    char *data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// Hàm thêm node
BSTNode* insert_bst(BSTNode *root, const char *data);

// Tìm node
BSTNode* search_bst(BSTNode *root, const char *target);

void inorder_bst(BSTNode *root);

void free_bst(BSTNode *root);

#endif
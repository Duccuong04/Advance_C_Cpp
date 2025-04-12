#include "CSV_Reader.h"
#include "User_List.h"
#include "Binary_Search_Tree.h"

#define DATABASE_PATH "data/infor.csv"

int main() {
    Node *nameList = NULL;
    Node *phoneList = NULL;

    // Đọc CSV và lưu vào 2 danh sách liên kết đã sắp xếp
    readCSV(DATABASE_PATH, &nameList, &phoneList);

    printf("\nName list (sorted):\n");
    print_list(nameList);

    printf("\nPhone list (sorted):\n");
    print_list(phoneList);

    // Tạo BST từ danh sách liên kết
    BSTNode *nameTree = NULL;
    BSTNode *phoneTree = NULL;

    Node *cur = nameList;
    while (cur) {
        nameTree = insert_bst(nameTree, cur->data);
        cur = cur->next;
    }

    cur = phoneList;
    while (cur) {
        phoneTree = insert_bst(phoneTree, cur->data);
        cur = cur->next;
    }

    // In BST in-order
    printf("\nBST theo TEN:\n");
    inorder_bst(nameTree);

    printf("\nBST theo SDT:\n");
    inorder_bst(phoneTree);

    // Tìm kiếm ví dụ
    const char *query = "Toni Kroos";
    BSTNode *found = search_bst(nameTree, query);
    if (found)
        printf("\nFound: %s\n", found->data);
    else
        printf("\nCan not find: %s\n", query);

    // Giải phóng bộ nhớ
    free_list(nameList);
    free_list(phoneList);
    free_bst(nameTree);
    free_bst(phoneTree);

    return 0;
}

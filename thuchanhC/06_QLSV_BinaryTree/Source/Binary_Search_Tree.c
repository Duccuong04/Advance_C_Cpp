// === BST.c ===
#include "Binary_Search_Tree.h"

BSTNode* create_bst_node(const char *data) {
    BSTNode *node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = (char*)malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->left = node->right = NULL;
    return node;
}

BSTNode* insert_bst(BSTNode *root, const char *data) {
    if (root == NULL) return create_bst_node(data);

    int cmp = strcmp(data, root->data);
    if (cmp < 0)
        root->left = insert_bst(root->left, data);
    else if (cmp > 0)
        root->right = insert_bst(root->right, data);

    return root;
}

BSTNode* search_bst(BSTNode *root, const char *target) {
    if (root == NULL || strcmp(root->data, target) == 0)
        return root;

    if (strcmp(target, root->data) < 0)
        return search_bst(root->left, target);
    else
        return search_bst(root->right, target);
}

void inorder_bst(BSTNode *root) {
    if (root) {
        inorder_bst(root->left);
        printf("%s\n", root->data);
        inorder_bst(root->right);
    }
}

void free_bst(BSTNode *root) {
    if (root) {
        free_bst(root->left);
        free_bst(root->right);
        free(root->data);
        free(root);
    }
}

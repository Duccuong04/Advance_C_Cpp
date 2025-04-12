#include "User_List.h"

Node* create_node(const char *data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = (char*)malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void add_sorted(Node **head, const char *data) {
    Node *new_node = create_node(data);

    if (*head == NULL || strcmp(data, (*head)->data) < 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;
    while (current->next && strcmp(data, current->next->data) > 0) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

void print_list(Node *head) {
    while (head) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

void free_list(Node *head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}
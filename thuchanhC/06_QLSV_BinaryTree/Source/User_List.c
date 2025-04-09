#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/User_List.h"

void add_node(Node **head, const char *data) {
    if (data == NULL) return; // tránh segfault

    // tạo node mới
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = (char*)malloc(strlen(data) + 1);
    strcpy(new_node->data, data);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next) current = current->next;
        current->next = new_node;
    }
}


void print_list(Node *head, const char *label) {
    printf("%s:\n", label);
    Node *current = head;
    while (current) {
        printf("  %s\n", current->data);
        current = current->next;
    }
}

void free_list(Node *head) {
    Node *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }
}

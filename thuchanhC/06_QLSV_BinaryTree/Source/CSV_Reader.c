#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/CSV_Reader.h"
#include "../Header/User_List.h"

void free_user(User *user) {
    free(user->name);
    free(user->addr);
    free(user->phone);
}

void readCSV(const char *file_name, Node **nameList, Node **phoneList) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Can't open file!\n");
    }

    char line[100];
    fgets(line, sizeof(line), file); // bỏ dòng tiêu đề

    // in tiêu đề
    printf("%-20s %-5s\t %-20s\t %-15s\n", "Name", "Age", "Address", "Phone" "Number");

    while (fgets(line, sizeof(line), file)) {
        User user;
        char *token = strtok(line, ",");
        user.name = (char*)malloc(sizeof(strlen(token) + 1));
        strcpy(user.name, token);

        token = strtok(NULL, ",");
        user.age = atoi(token);

        token = strtok(NULL, ",");
        user.addr = (char*)malloc(sizeof(strlen(token) + 1));
        strcpy(user.addr, token);

        token = strtok(NULL, ",");
        user.phone = (char*)malloc(sizeof(strlen(token) + 1));
        strcpy(user.phone, token);

        printf("%-20s %-5d\t %-20s\t %-15s\n", user.name, user.age, user.addr, user.phone);

        // Thêm vào danh sách liên kết
        add_node(nameList, user.name);
        add_node(phoneList, user.phone);

        free_user(&user);
    }

    fclose(file);
}

// === CSV_Reader.c ===
#include "CSV_Reader.h"

typedef struct {
    char *name;
    int age;
    char *addr;
    char *phone;
} User;

static void free_user(User *user) {
    free(user->name);
    free(user->addr);
    free(user->phone);
}

void readCSV(const char *filename, Node **nameList, Node **phoneList) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Can't open file!!!\n");
        return;
    }

    char line[256];
    fgets(line, sizeof(line), file); // Bỏ qua dòng tiêu đề

    printf("%-20s %-5s\t %-20s\t %-15s\n", "Name", "Age", "Address", "Phone Number");

    while (fgets(line, sizeof(line), file)) {
        User user;

        char *token = strtok(line, ",");
        if (!token) continue;
        user.name = (char*)malloc(strlen(token) + 1);
        strcpy(user.name, token);

        token = strtok(NULL, ",");
        if (!token) { free(user.name); continue; }
        user.age = atoi(token);

        token = strtok(NULL, ",");
        if (!token) { free(user.name); continue; }
        user.addr = (char*)malloc(strlen(token) + 1);
        strcpy(user.addr, token);

        token = strtok(NULL, ",\n");
        if (!token) {
            free(user.name);
            free(user.addr);
            continue;
        }
        user.phone = (char*)malloc(strlen(token) + 1);
        strcpy(user.phone, token);

        // In và thêm vào danh sách
        printf("%-20s %-5d\t %-20s\t %-15s\n", user.name, user.age, user.addr, user.phone);

        add_sorted(nameList, user.name);
        add_sorted(phoneList, user.phone);

        free_user(&user);
    }

    fclose(file);
}

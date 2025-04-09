#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_PATH "..\\Data\\information.csv" // đường dẫn file csv

typedef struct
{
    char *name;
    int age;
    char *addr;
    char *phone;
} User;

// free các member trong user đã cấp phát động
void free_user(User *user)
{
    free(user->name);
    free(user->addr);
    free(user->phone);
} 

void readCSV(const char *file_name)
{
    FILE *file = fopen(file_name, "r");

    // kiểm tra nếu không mở được
    if (file == NULL)
        printf("Can't open file!!!\n");

    // bộ đệm lưu từng dòng từ file
    char line[100];

    // bỏ qua dòng tiêu đề
    fgets(line, sizeof(line), file);    // Name, Age, Address, Phone Number

    // in tiêu đề
    printf("%-20s %-5s\t %-20s\t %-15s\n", "Name", "Age", "Address", "Phone" "Number");
    
    while (fgets(line, sizeof(line), file)) // John Doe, 30, 123 Main St, 555-1234
    {
        User user;  // biến lưu thông tin user tạm thời

        /* Tách tên từ dòng hiện tại */
        char *token = strtok(line, ",");
        user.name = (char*)malloc(sizeof(strlen(token) + 1)); // + 1 cho kí tự '/0'
        strcpy(user.name, token);    // sao chép toàn bộ chuỗi token vào user.name

        /* Tách tuổi */
        token = strtok(NULL, ",");  // "30", truyền vào NULL, tự động trỏ tới chuỗi
        user.age = atoi(token);     // chuyển chuỗi thành số

        /*Tách địa chỉ */
        token = strtok(NULL, ",");
        user.addr = (char*)malloc(sizeof(strlen(token) + 1));
        strcpy(user.addr, token);   

        /* Tách sdt */
        token = strtok(NULL, ",");
        user.phone = (char*)malloc(sizeof(strlen(token) + 1));
        strcpy(user.phone, token);

        printf("%-20s %-5d\t %-20s\t %-15s\n", user.name, user.age, user.addr, user.phone);

        free_user(&user);
    }
}

int main(int argc, char const *argv[])
{
    readCSV(DATABASE_PATH);
    return 0;
}
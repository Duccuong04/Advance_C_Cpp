#include <stdio.h>
#include <stdlib.h>

#define FILE_CREATE_FAILDED -1

#define DATABASE_PATH "..\\Data\\information.csv"

//  đường dẫn tuyệt đối: "D:\\C_C++_Advanced\\Binary_Search-File_operation\\FILE\\information.csv"
//  đường dẫn tương đối: ..\\FILE\\information.csv

int main(int argc, char const *argv[])
{
    // Mở file để ghi, nếu chưa có tạo file mới
    FILE *file = fopen(DATABASE_PATH, "w");

    // kiểm tra nếu không mở được
    if (file == NULL)
    {
        printf("Can't create file\n");
        return FILE_CREATE_FAILDED;
    }

    // Ghi dòng tiêu đề vào file csv
    fprintf(file, "Name, Age, Address, Phone Number\n");

    // Ghi các thông tin vào file csv
    fprintf(file, "John Doe, 30, 123 Main St, 555-1234\n");
    fprintf(file, "Jane Smith, 25, 456 Oak St, 555-5678\n");
    fprintf(file, "Bob Johnson, 40, 789 Pine St, 555-8765\n");
    fprintf(file, "Tam, 21, 768 Thien Tan, 03211432\n");
    fprintf(file, "Yen, 19, 768 Thanh Phu, 03211657\n");
    fprintf(file, "Tung, 23, 768 Tri An, 03211657\n");
    fprintf(file, "Tuan, 21, 768 Thien Tan, 032654645\n");

    // đóng file sau khi ghi
    fclose(file);

    printf("File created succesfully\n");

    return 0;
}
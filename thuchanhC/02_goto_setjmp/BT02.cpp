#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
const char *exception_msg;

typedef enum {
    NO_ERROR, 
    FILE_ERROR, 
    NETWORK_ERROR, 
    CALCULATION_ERROR
} ErrorCodes;

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x, msg) \
exception_code = x; \
exception_msg = msg; \
longjmp(buf, x); \

void readFile() {
    printf("Đọc file...\n");
    THROW(FILE_ERROR, "Lỗi đọc file: File không tồn tại.");
}

void networkOperation() {
    printf("Kết nối mạng...\n");
    int networkStatus = 0; // Giả lập lỗi mạng
    if (networkStatus == 0) {
        THROW(NETWORK_ERROR, "Lỗi mạng: Không thể kết nối!");
    }
    printf("Kết nối thành công!\n");
}

void calculateData() {
    printf("Thực hiện tính toán...\n");
    int divisor = 0; // Giả lập lỗi chia cho 0
    if (divisor == 0) {
        THROW(CALCULATION_ERROR, "Lỗi tính toán: Chia cho 0.");
    }
    printf("Kết quả: %d\n", 100 / divisor);
}

int main() {
    exception_code = NO_ERROR;

    TRY {
        readFile();
    }
    CATCH(FILE_ERROR) {
        printf("%s\n", exception_msg);
    }

    TRY {
        networkOperation();
    }
    CATCH(NETWORK_ERROR) {
        printf("%s\n", exception_msg);
    }
    
    TRY {
        calculateData();
    }
    CATCH(CALCULATION_ERROR) {
        printf("%s\n", exception_msg);
    }

    printf("Chương trình kết thúc.\n");
    return 0;
}

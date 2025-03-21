#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;           // Mã lỗi
const char *exception_msg;    // Thông điệp lỗi

// Định nghĩa TRY-CATCH-THROW với mã lỗi và thông điệp lỗi
#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(code, msg) do { exception_code = code; exception_msg = msg; longjmp(buf, code); } while(0)

// Lỗi định nghĩa trước
typedef enum {
    NO_ERROR,
    DIVIDE_BY_0,
    NEGATIVE_SQRT
} ErrorCodes;

// Hàm thử nghiệm: Chia hai số
double divide(int a, int b) {
    if (b == 0) {
        THROW(DIVIDE_BY_0, "Lỗi: Phép chia cho 0!"); // Ném lỗi chia 0
    }
    return (double)a / b;
}

// Hàm thử nghiệm: Căn bậc hai số âm
double sqrt_custom(double x) {
    if (x < 0) {
        THROW(NEGATIVE_SQRT, "Lỗi: Không thể tính căn bậc hai của số âm!"); // Ném lỗi căn bậc hai âm
    }
    return x * 0.5;  // Giả lập sqrt(x) cho mục đích demo
}

int main() {
    TRY {
        printf("Kết quả phép chia: %0.3f\n", divide(10, 0));
    }
    CATCH(DIVIDE_BY_0) {
        printf("%s\n", exception_msg);
    }

    TRY {
        printf("Kết quả căn bậc hai: %0.3f\n", sqrt_custom(-4));
    }
    CATCH(NEGATIVE_SQRT) {
        printf("%s\n", exception_msg);
    }

    printf("Chương trình tiếp tục chạy...\n");
    return 0;
}

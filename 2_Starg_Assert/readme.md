**1. Thư viện starg**

- Tương tự variadic macro
- Cung cấp các phương thức để làm việc với các hàm có số lượng tham số đầu vào không cố định

Ví dụ:

***Cách 1:***

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    va_list args;

    va_start(args, count);

    int result = 0;

    for(int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);
    
    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", sum(5, 0, 1, 3, 5, 6));
    return 0;
}
```
***

Giải thích:

- va_list: 

    ✦ Kiểu dữ liệu để đại diện cho danh sách đối số các biến số. Trong thư viện được định nghĩa là: ```typedef char* args;```, con trỏ args trỏ đến chuỗi được truyền vào hàm sum ```(args = "int count, 0, 1, 3, 5, 6")```, các kí tự trong chuỗi có địa chỉ liền kề nhau.

    ✦ Ví dụ `0xa0 ('i') 0xa1('n') 0xaa('1')`

- va_start: Bắt đầu một danh sách đối số biến đổi. Nó cần được gọi trước khi truy cập các đối số biến đổi đầu tiên. ```va_start(args, count);```

    ✦ Truyền vào 2 tham số con trỏ `args` và nhãn `count`. Trình biên dịch sẽ so sánh từng kí tự  của 2 chuỗi `"int count, 0, 3, 5, 6, 7"` và `"count"`. Con trỏ `args` sẽ truy cập đến từng địa chỉ của từng kí tự trong chuỗi, lấy ra giá trị được lưu sau đó sẽ so sánh với kí tự trong label `"count"` được truyền vào.

    ✦ Sau bước này chuỗi `"int count, 0, 3, 5, 6, 7"` được tách thành `"0, 3, 5, 6, 7"` (chỉ còn những tham số thay đổi)

- va_arg(args, int): Truy cập một đối số trong danh sách. Hàm này nhận một đối số của kiểu được xác định bởi tham số thứ hai

    ✦ Mỗi lần được gọi sẽ tách lần lượt từng kí tự trong chuỗi, sau đó ép kiểu về kiểu dữ liệu được khai báo bởi tham số thứ hai
    
    ✦ Ví dụ gọi lần thứ nhất lấy kí tự `'0'`, gọi lần thứ hai lấy kí tự `'3'`

- va_end: Kết thúc việc sử dụng danh sách đối số biến đổi. Nó cần được gọi trước khi kết thúc hàm.

    ✦ Thu hồi lại địa chỉ của con trỏ args

***Cách 2***

```c
/*
Tính tổng của một dãy số bất kì sử dụng thư viện stdarg nhưng tối ưu hơn
Bắt đầu từ giá trị của count kết thúc khi gặp số 0
*/
#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, 0)

int sum(int count,...)
{
    va_list args;

    va_start(args, count);

    int result = count; // bắt đầu tính tổng từ count
    int value;

    while((value = va_arg(args, int)) != 0)
    {
        result += value;
    }

    va_end(args);

    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", tong(3, 2, 4, 5, 7)); // sum(3, 2, 4, 5, 7, 0)
    return 0;
}
```

***Cách 3: loại bỏ nhược điểm gặp số 0 là dừng của cách 2***

```c
/*
Tính tổng của một chuỗi bất kì 
*/
#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__, '\n')

int sum(int count,...)
{
    va_list args;
    va_list check;

    va_start(args, count);

    va_copy(check, args);

    int result = count; // bắt đầu tính tổng từ count
    int value;

    while(( va_arg(check, char*)) != (char*)'\n')
    {
        result += va_arg(args, int);
    }

    va_end(args);

    return result;
}

int main(int argc, char const *argv[])
{
    printf("Tong = %d\n", tong(3, 2, 4, 0, 5, 6)); // sum(3, 2, 4, 0, 5, 7, '/n')
    return 0;
}
```
- Khai báo thêm 1 con trỏ check trỏ đến chuỗi `"int count, 3, 2, 4, 0, 5, 6"`
- Sử dụng thêm hàm `var_copy`: sao chép địa chỉ mà con trỏ args đang trỏ tới, thao tác với con trỏ check

📌 Code ứng dụng thư viện stdarg trong thực tế, đọc và xử trí tín hiệu và giá trị của các cảm biến

```c
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    TEMPERATURE_SENSOR,
    PRESSURE_SENSOR
} SensorType;

void processSensorData(SensorType type, ...) {
    va_list args;
    va_start(args, type);

    switch (type) {
        case TEMPERATURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            float temperature = va_arg(args, double); // float được promote thành double
            printf("Temperature Sensor ID: %d, Reading: %.2f degrees\n", sensorId, temperature);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* additionalInfo = va_arg(args, char*);
                printf("Additional Info: %s\n", additionalInfo);
            }
            break;
        }
        case PRESSURE_SENSOR: {
            int numArgs = va_arg(args, int);
            int sensorId = va_arg(args, int);
            int pressure = va_arg(args, int);
            printf("Pressure Sensor ID: %d, Reading: %d Pa\n", sensorId, pressure);
            if (numArgs > 2) {
                // Xử lý thêm tham số nếu có
                char* unit = va_arg(args, char*);
                printf("Unit: %s\n", unit);
            }
            break;
        }
    }

    va_end(args);
}

int main() {
    processSensorData(TEMPERATURE_SENSOR, 2, 1, 36.5, "Room Temperature");
    processSensorData(PRESSURE_SENSOR, 2, 2, 101325);
    return 0;
}
```
***

**2. Thư viện Assert**

- Dùng để phát hiện lỗi, debug chương trình, thể hiện lỗi cụ thể ở một vị trí cụ thể trong code
- Nếu điều kiện đúng (true), không có gì xảy ra và chương trình tiếp tục thực thi.
- Nếu điều kiện sai (false), chương trình dừng lại và thông báo một thông điệp lỗi.

📌 Ví dụ 1: 

```c
#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    
    int x = 5;

    assert(x == 5);

    //chương trình chỉ thực thi khi điều kiện đúng
    printf("X = %d", x);
    return 0;
}
```
*Output*

`X = 5`

📌 Ví dụ 2:

```c
#include <stdio.h>
#include <assert.h>

int main(int argc, char const *argv[])
{
    
    int x = 5;

    assert(x > 10 && "X phải lớn hơn 10" );

    //chương trình chỉ thực thi khi điều kiện đúng
    printf("X = %d", x);
    return 0;
}
``` 
*Output*

`Assertion failed: x > 10 && "X phải lớn hơn 10", file Assert2.c, line 9`

- Macro assert dùng để debug:
`#define LOG(condition, cmd) assert(condition && #cmd)`

📌 Ví dụ: Thiết lập level nằm trong khoảng cho phép

```c
#include <assert.h>

#define ASSERT_IN_RANGE(val, min, max) assert((val) >= (min) && val <= (max))

void set_level(int level)
{
    ASSERT_IN_RANGE(level, 1, 10);
    // thiết lập cấp độ bằng macro assert
}
```




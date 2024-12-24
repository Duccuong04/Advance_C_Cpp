# Advance_C_Cpp
Contents

<details>
<summary>LESSON 1: COMPILER - MACRO</summary> 

---

**I. Compiler**
- Là quá trình chuyển đổi ngôn ngữ bậc cao sang ngôn ngữ máy.
- Gồm 4 giai đoạn
![alt text](image.png)

***Preprocessor (tiền xử lý)***: `gcc -E main.c -o main.i`. Các file trong source code (a.c, a.h, b.h, b.c, main.c,…) sẽ được biên dịch thành 1 file main.i. Ở giai đoạn này, trình biên dịch sẽ:

- Copy toàn bộ file thư viện (ví dụ #include <stdio.h>, #include “hello.h”,…)
- Thay thế các nội dung được #define 
- Xoá toàn bộ chú thích, các hàm và biến khai báo được giữ nguyên.

***Compiler***: File main.i được biên dịch thành file main.s (bao gồm các dòng lệnh được viết bằng ngôn ngữ assembly)

![alt text](image-1.png)

***Assembler***: Biên dịch ngôn ngữ assembly trong file main.s thành ngôn ngữ máy (file main.o)

***Linker***: 1 hoặc nhiều main.o sẽ được liên kết lại thành file thực thi (.exe)

---

**II. Macro**
-	Macro là một khái niệm dùng để định nghĩa một tập hợp các hướng dẫn tiền xử lý
-	Dùng để thay thế một chuỗi mã nguồn bằng một chuỗi khác trước khi chương trình biên dịch.
-	Giúp giảm lặp lại mã, dễ bảo trì chương trình.
-	Macro được định nghĩa bằng cách sử dụng chỉ thị tiền xử lý #define
-	Trong C, macro chia làm 3 loại: chỉ thị bao hàm tệp, chỉ thị định nghĩa, chỉ thị biên dịch có điều kiện.

**1. Chỉ thị bao hàm tệp (#include)** 
-	Gồm 2 loại:
    \*  <> (ví dụ #include <stdio.h>): khi run code, trình biên dịch tìm đến vị trí đã cài đặt file thư viện stdio.h trong bộ nhớ máy tính, sau đó sao chép toàn bộ nội dung file này vào file .i
    \* “…”: tìm trong thư mục chứ dự án hiện tại file nào có tên … sau đó sao chép toàn bộ nội dung file này vào file .i

    ![alt text](image-2.png)

**2. Chỉ thị định nghĩa**

***#define***: Định nghĩa, thay thế một tên, biến hoặc hàm 
![alt text](image-3.png)
-	Định nghĩa  giá trị của SIZE1 là 5 và  định nghĩa hàm
![alt text](image-4.png)
-	Sau giai đoạn tiền xử lý, nội dung được define ở file .c được thay thế vào trong file .i

***undef***: hủy định nghĩa của một macro đã được định nghĩa trước đó bằng #define
```c
#include <stdio.h>

#define SIZE1 5

int main(int argc, char const *argv[])
{
    printf("SIZE1 = %d\n", SIZE1);

    #undef SIZE1

    #define SIZE1 50

    printf("SIZE1 = %d\n", SIZE1);
    /* code */
    return 0;
}
```
**3. Chỉ thị biên dịch có điều kiện**

**3.1.**

***#if*** sử dụng để bắt đầu một điều kiện tiền xử lý.
- Nếu điều kiện trong ***#if*** là đúng, các dòng mã nguồn sau ***#if*** sẽ được biên dịch
- Nếu sai, các dòng mã nguồn sẽ bị bỏ qua đến khi gặp ***#endif***

***#elif*** dùng để thêm một điều kiện mới khi điều kiện trước đó trong ***#if*** hoặc ***#elif*** là sai

***#else*** dùng khi không có điều kiện nào ở trên đúng.

Ví dụ
```c
#include <stdio.h>

#define ESP32 1
#define STM32 2
#define ATmega 3

#define MCU STM32

int main(int argc, char const *argv[])
{
    while (1)
    {
        #if MCU == STM32
            printf("STM32");
        
        #elif MCU == ESP32
            printf("ESP32");
        
        #else 
            printf("0");

        #endif

    }
    return 0;
}
```
**3.2.**

***#ifdef*** và ***#ifndef*** thường được sử dụng trong tạo file thư viện, tránh việc định nghĩa mã nguồn nhiều lần gây lỗi trong quá trình tiền xử lý file .i

- ***#ifdef*** dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro đã được định nghĩa thì mã nguồn sau #ifdef sẽ được biên dịch.
- ***#ifndef*** dùng để kiểm tra một macro đã được định nghĩa hay chưa, nếu macro chưa được định nghĩa thì mã nguồn sau #ifndef sẽ được biên dịch.
Ví dụ
```c
#ifndef TEST_H
#define TEST_H

void display();

#endif
```
**3. Một số toán tử trong macro**

***a##b***: nối chuỗi

***#x***: chuẩn hóa chuỗi

Ví dụ
```c
#include<stdio.h>

#define concatenate(a,b) a##b

#define tostring(c) #c
int main(int argc, char const *argv[])
{
    int giatri = 10;

    // nối 'gia' và 'tri' thành 'giatri'
    printf("giatri = %d\n", concatenate(gia,tri));

    // chuẩn hóa chuỗi
    printf("chuỗi đã chuẩn hóa: %s\n", tostring(abc));
    return 0;
}
```

***Variadic macro***
- Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi.
- Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau, dùng cho những hàm có tham số không xác định.

Ví dụ:

\__VA_ARGS__ sẽ thay thế vào dấu ...
```c
#include<stdio.h>

#define count_args(...) (sizeof(int[]){__VA_ARGS__}/sizeof(int));

#define sum(...)                \
int arr[] = {__VA_ARGS__};      \
int SUM = 0;                    \
int n = count_args(__VA_ARGS__);\
int i = 0;\
for(i = 0; i<n; i++)            \
{                               \
    SUM += arr[i];             \
}                               \
printf("SUM = %d\n", SUM);      \

int main(int argc, char const *argv[])
{
    sum(1,2,0,3,4);
    return 0;
}
```
</details>

<details>
<summary>LESSON 2: STDARG - ASSERT</summary>

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

</details>


<details>
<summary>LESSON 3: BITMASK </summary> 

### Bit mask

📌 Để tối ưu hóa bộ nhớ khi khai báo biến trong C, ta khai báo thư viện `#include <stdint.h>`, một số kiểu dữ liệu trong thư viện
```c
/*
    int, int32_t, uint32_t: 4 byte
    int8_t, uint8_t: 1 byte
    int16_t, uint16_t: 2 byte
*/
```
📌 Bit mask một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái (thao tác trên bit).

Ví dụ:

```c
/*
    uint8_t PORT_A = 0b00001101 (1 byte)
    bit 0: Pin_A0
    bit 1: Pin_A1 
    bit 2: Pin_A2
    .
    .
    .
    bit 8: Pin_A8

    Thao tác trên cụm bit này -> bit mask -> tối ưu hóa bộ nhớ
*/
```
📌 Các toán tử bitwise

- `AND (&), OR(|), XOR(^), NOT(~)`

![alt text](bitwise.png)

Ví dụ:

```c
uint8_t A = 0b01001001;
uint8_t B = 0b11101111;
    /*
    ~A = 0b10110110;
    A&B = 0b01001001;
    A|B = 0b11101111;
    A^B = 0b10100110;
    */
```

- `Shift left (<<) và Shift right (>>)`: phép dịch bit
- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

Ví dụ:

```c
uint8_t A = 0b01001001;
uint8_t B = 0b11101111;
    A = A << 2; //0b00100100;
    B = B >> 3; //0b00011101; 
    // bit dấu chỉ có ý nghĩa khi số có dấu (-8)
```

📌 Ví dụ sử dụng bit mask và giải thích

```c

#include <stdio.h>
#include <stdint.h>

/*
    Sử dụng macro và bit wise để khai báo các tính năng
    Phép dịch bit 1 << 0: 0b00000001 << 0
                  1 << 1: 0b00000001 << 1 để khai báo tính năng TSHIRT
    8 tính năng nằm trong 1 byte -> tối ưu bộ nhớ
*/


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

/*
    Sử dụng bit wise & để bật 1 tính năng mà không ảnh hưởng đến bit khác
    enableFeature(&options, GENDER | TSHIRT | HAT);
    uint8_t options = 0; // 0b00000000
    0b00000000
    &
    0b00000111
    ----------
    0b00000111 -> thao tác với bit mà không ảnh hưởng tới bit khác

*/

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

/*
    Sử dụng bit wise | để thao tác
    options = 0b00000111;
    disableFeature(&options, TSHIRT);
    0b00000111
    |
   ~0b00000010
   ------------
    0b00000101
*/

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
    

    // Thêm các điều kiện kiểm tra cho các tính năng khác
}



int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}


```

**Output**

```c
Selected Features:
- Gender
- Hat
feature selected: 1
feature selected: 0
feature selected: 1
feature selected: 0
feature selected: 0
feature selected: 0
feature selected: 0
feature selected: 0
```
- Sử dụng phép dịch bit và macro để khai báo các tính năng (tối ưu bộ nhớ)
- Dùng toán tử bit wise để bật tắt các tính năng mà không ảnh huởng đến tính năng khác, kiểm tra xem tính năng nào đã được bật.

</details>


<details>
<summary>LESSON 4: ADVANCED POINTER</summary> 

### Pointer

- Là biến chứ địa chỉ bộ nhớ của một đối tượng khác (biến, mảng, hàm) -> thao tác trên bộ nhớ 1 cách linh hoạt hơn

- Cách lưu giá trị trong bộ nhớ:

```c
int a = 12; // 0b00000000 00000000 00000000 00001100

0x01 -> 00001100 (LSB)
0x02 -> 00000000
0x03 -> 00000000
0x04 -> 00000000 (MSB)

// float = sign (1 bit) + exponent (8 bits) + mantissa (23 bits)
// double = sign (1 bit) + exponent (11 bits) + mantissa (52 bits)



```

```c

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int test = 2;

    int *ptr = &test;

    printf("Size of pointer: %d bytes\n", sizeof(ptr));

    printf("Address of test: %p\n", &test);
    printf("Address of test: %p\n", ptr);

    printf("Value of test: %d\n", test);
    printf("Value of test: %d\n", *ptr); // dereference

    return 0;
}


```

Output

```c
Size of pointer: 8 bytes
Address of test: 000000DA42BFF974
Address of test: 000000DA42BFF974
Value of test: 2
Value of test: 2
```
- Khai báo con trỏ ptr trỏ đến địa chỉ của biến test

- Toán tử giải tham chiếu lấy ra giá trị của địa chỉ đang trỏ đến

📌 Kích thước của con trỏ phụ thuộc vào kiến trúc máy tính và trình biên dịch hoặc kiến trúc vi xử lý.

- Vì đang sử dụng máy tính cá nhân 64bit nên kích cỡ con trỏ là 8 byte

📌 Kiểu dữ liệu khai báo ảnh hưởng đến việc truy xuất dữ liệu ra (con trỏ kiểu int đọc 4 byte trong 8 byte)

📌 Ví dụ dùng con trỏ để đổi giá trị của 2 biến với nhau

```c
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}
```

**Void Pointer**

- Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

- Con trỏ kiểu void trỏ tới biến kiểu int, đọc giá trị cần sử dụng ép kiểu con trỏ `(int* )ptr_void`, giải tham chiếu để đọc giá trị, lúc này trình biên dịch sẽ biết được cần đọc bao nhiêu byte dữ liệu trong 8 byte lưu con trỏ void. 

📌 Ví dụ:

```c
#include <stdio.h>
#include <stdint.h>

int main(int argc, char const *argv[])
{
    // khai báo con trỏ void để trỏ tới các kiểu dữ liệu khác nhau
    void *ptr_void;

    // con trỏ void trỏ tới địa chỉ biến int
    int var_int = 10;
    ptr_void = &var_int;

    printf("Addr of = %p, Value = %d\n", ptr_void, *(int *)ptr_void);

    // Ép con trỏ void sang uint8_t* để đọc từng byte
    uint8_t *byte_ptr = (uint8_t *)ptr_void;

    for (int i = 0; i < 4; i++) // đọc từng byte trong 4 byte
    {
        printf("Addr of = %p, Value = %d\n", (byte_ptr + i), *(byte_ptr + i));
    }

    return 0;
}
```

Output:

```c
Addr of = 0000005BC0FFF9B4, Value = 10
Addr of = 0000005BC0FFF9B4, Value = 10
Addr of = 0000005BC0FFF9B5, Value = 0
Addr of = 0000005BC0FFF9B6, Value = 0
Addr of = 0000005BC0FFF9B7, Value = 0
```

- `ptr_void` chỉ thể hiện địa chỉ bắt đầu của con trỏ (byte đầu tiên trong 4 byte cần đọc)

- Với int *ptr:

sizeof(int) = 4 (giả sử trên hệ thống 32-bit).
ptr + 1 sẽ tăng địa chỉ của ptr thêm 4 byte.

- Với uint8_t *ptr:

sizeof(uint8_t) = 1.


ptr + 1 sẽ tăng địa chỉ của ptr thêm 1 byte.

📌 Trỏ đến địa chỉ khác nếu người dùng muốn

```c
    // trỏ tới địa chỉ khác
    double var_double = 3.14;
    ptr_void = &var_double;

     printf("Addr of = %p, Value = %.3f\n", ptr_void, *(double *)ptr_void);
```

📌 Tiếp tục trỏ đến một mảng, in ra từng kí tự có trong mảng

```c
     // trỏ đến 1 mảng
     char arr[] = "hello"; // gồm các kí tự h,e,l,l,o,\0
     ptr_void = arr;

     printf("Chuỗi: ");
     for(int i = 0; i <= (sizeof(arr)/sizeof(arr[0])); i++)
     {
        printf("%c\n", *(char* )(ptr_void + i));
     }
     printf("\n");
```

📌 Mảng con trỏ void, những phần tử của nó là địa chỉ của đối tượng

```c
  /*Khai báo mảng con trỏ void*/
    void *ptr[] = {&var_int, &var_double, arr};
    printf("ptr[0] = %d\n", *(int* )ptr[0]);
    printf("ptr[1] = %f\n", *(double* )ptr[1]);

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("%c\n", *(char* )(ptr[2] + i));
    }
```


- Con trỏ void có thể trỏ đến bất cứ địa chỉ nào tiếp theo -> linh hoạt, giảm dung lượng bộ nhớ chương trình

**2. Pointer to function**

- Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.

- Cú pháp: `<return_type> (* func_pointer)(<data_type_1>, <data_type_2>);`, kiểu trả về và tham số phải giống với hàm mà nó muốn trỏ tới

- `void sum(int a, int b);`, con trỏ hàm lưu trữ địa chỉ: `void (*func_ptr)(int, int);`

- `int test(double a, char b, short c);` <- `int(*func_ptr)(double, char char);`

📌 3 cách dùng con trỏ hàm:

```c
#include <stdio.h>

void tong(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void hieu(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void tich(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

/* Cách 2: Sử dụng con trỏ hàm làm tham số của 1 hàm */
void tinhtoan(void(*pheptoan)(int, int), int a, int b)
{
    pheptoan(a,b);
}
int main(int argc, char const *argv[])
{

    int a = 2, b = 3;
       
    /* Cách 1: Sử dụng con trỏ ham để gọi các phép toán */
    void(*ptr)(int, int); // khai báo con trỏ hàm
    ptr = tong;           // hoặc ptr = &tong; trỏ đến địa chỉ của hàm tổng 
    ptr(a, b);            // truyền vào tham số

    ptr = hieu;
    ptr(a, b);

    ptr = tich;
    ptr(a, b);

    /* Cách 2: Sử dụng con trỏ hàm làm tham số của 1 hàm */
    tinhtoan(tong, a, b);
    tinhtoan(hieu, a, b);
    tinhtoan(tich, a, b);

    /* Cách 3: Sử dụng mảng con trỏ hàm để gọi các phép toán*/
   void (*arr[])(int, int) = {tong, hieu, tich};
   arr[0](a, b);
   arr[1](a, b);
   arr[2](a, b);

  
    return 0;
}

```

📌 Ưu điểm so với gọi hàm thông thường: tăng tính linh hoạt (vì quá trình gọi hàm ở Run time)

**3. Pointer to Constant**

- Chỉ được phép đọc, không được phép thay đổi giá trị đang trỏ tới thông qua con trỏ

```c
int const *ptr_const; 
const int *ptr_const;
```
```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int var = 5;
    const int* ptr = &var;
    var = 6; // no error
    ptr = 6; //error
    return 0;
}
```
**4. Constant to Pointer**

- Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.

```c
int *const const_ptr = &value;
```
- Ứng dụng: quản lý thanh ghi trong vi điều khiển, cố định địa chỉ cụ thể (ODR, GPOIC, CPHOL,...)

**5. NULL Pointer**

- Null Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.

📌 Ví dụ: khởi tại giá trị ban đầu là NULL để tránh trỏ đến giá trị rác

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *ptr = NULL;

    printf("Addr of ptr: %p\n", ptr);

    if(ptr == NULL)
    {
        printf("Pointer is NULL, can't dereference\n");
    }

    else
    {
        printf("Ptr = %d\n", *ptr);
    }
    return 0;
}

```

**6. Pointer to pointer**

- Con trỏ đến con trỏ (Pointer to Pointer) là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ.

Ví dụ:

```c
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a= 5;

    int *p = &a;

    int **ptp = &p;

    printf("Addr of a = %p %p %p\n", &a, p, *ptp);
    printf("Value of a = %d %d %d\n", a, *p, **ptp);

    return 0;
}
```

```c
Addr of a = 000000F7307FFD84 000000F7307FFD84 000000F7307FFD84
Value of a = 5 5 5
```

</details>

<details>
<summary>LESSON 5: STORAGE CLASSES</summary> 

### Extern_Static_Voltage_Register

**1.Extern**

- Sử dụng lại biến, hàm,... từ file khác (tái sử dụng mã nguồn)

- Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.

📌 Ví dụ 1: 

`file test.c`
```c
#include <stdio.h>

int var = 10;

void display()
{
    printf("%d\n", var);
}
```

`file main.c`, sử dụng các biến và hàm từ file test bằng từ khóa `extern` và không cần khai báo `"#include test.c"` -> gây lỗi khi vô tình được khai báo nhiều lần

```c
#include <stdio.h>

extern int var; // extern int var = 200; -> error

extern void display();

int main(int argc, char const *argv[])
{
    display();  
    return 0;
}
```
**Lưu ý**

- Chỉ khai báo chứ không định nghĩa giá trị cụ thể của biến, nội dung của hàm sau từ khóa `extern`

- Khi biên dịch cần liên kết 2 file `-o` qua câu lệnh `gcc main.c test.c -o a.exe`

- Chỉ sử dụng cho biến toàn cục

📌 Ví dụ 2:

`file test.h`

```c
#ifndef TEST_H
#define TEST_H

extern int var_global;

extern void display();

#endif
```
`file test.c`

```c
#include <stdio.h>
#include "test.h"

int var_global = 10;

void display()
{
    printf("%d\n", var_global);
}
```

`file main.c`

```c
#include <stdio.h>
#include "test.h"

int main(int argc, char const *argv[])
{
    var_global = 100;
    display();
    return 0;
}
```

- File .h sử dụng lại các biến, hàm mà nội dung của biến và hàm đó đã được khai báo ở file .c.

**2. Static**
**2.1 Static local variales**

- Khi static được sử dụng với local variables, nó giữ giá trị của biến khai báo cố định qua các lần gọi hàm, không giải phóng địa chỉ sau khi hàm kết thúc

-  Giữ phạm vi của biến chỉ trong hàm đó

📌 Ví dụ:

```c
#include <stdio.h>

int *ptr = NULL;

void upper()
{
    static int a = 0;
    ptr = &a;
    printf("addr of a: %p\n", &a);
    printf("a = %d\n", ++a);
}

int main(int argc, char const *argv[])
{
    upper(); // a = 1
    upper(); // a = 2
    *ptr = 9;
    upper(); // a = 10;
    return 0;
}

```

Output

```c
addr of a: 00007FF6018C7038
a = 1
addr of a: 00007FF6018C7038
a = 2
addr of a: 00007FF6018C7038
a = 10
```
- Sau khi kết thúc hàm, địa chỉ của biến `a` không được giải phóng nên lần gọi tiếp theo giá trị của `a` bằng 2

- Có thể thay đổi giá trị của biến static cục bộ a thông qua con trỏ.

**2.2 Static local variales**

- Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.

📌 Ví dụ:

`test.h`

```c
#ifndef TEST_H
#define TEST_H

extern int b;

//extern int a;

//extern void display();

extern void test();

#endif
```

`test.c`

```c
#include <stdio.h>
#include "test.h"

static int a = 10;

int b = 2;

static void display()
{
    printf("file test.c/n");
}

void test()
{
    printf("Hello");
}
```

`main.c`

```c
#include <stdio.h>
#include "test.h"

int main(int argc, char const *argv[])
{
    //printf("%d\n", a);
    printf("%d\n", b);
    //display();
    test();
    return 0;
}

```
- `static int a = 10`, chỉ cho phép ở trong phạm vi file chứ nó, nếu cố tính truy cập thông qua extern -> báo lỗi

- Dùng để thiết kế các file thư viện

**3.Register**
- Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM -> nhằm tăng tốc độ truy cập. 

- Thông thường khai báo biến, địa chỉ của nó được lưu trên RAM

- CPU chuyển từ RAM sang register sau đó chuyển sang ALU (bộ xử lý tính toán)
giảm tính linh hoạt của register

📌 Ví dụ:

```c
#include<stdio.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    clock_t start_time = clock();
    int i;

    for(i = 0; i < 200000000; i++)
    {
        // do something
    }

    // tính thời gian chạy bằng mili giây

    double time_taken = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;

    printf("Run time = %f", time_taken);
    return 0;
}

```
Output

`Run time = 0.072000`

- Khai báo biến với register `register int i;` , lưu trên thanh ghi thay vì RAM output: `Run time = 0.071000` .

- Register chỉ dùng cho biến cục bộ

- Sử dụng cho việc tính toán số học

- Việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.

**4.Volatile**


```c
#include "stm32f10x.h"

volatile int i = 0;
int a = 100;

int main()
{
	
	while(1)
	{
		i = *((int*) 0x20000000);
		if (i > 0)
		{
			break;
		}
		
	}
	a = 200;
}

```

- Trình biên dịch đã tối ưu biến a, xóa khỏi chương trình, giữ mặc định luôn là `100` -> dẫn đến không đọc được giá trị thay đổi về sau

- `Volatile` ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.

</details>

<details>
<summary>LESSON 6: GOTO_SETJMP</summary>

</details>

<details>
<summary>LESSON 7: STRUCT_UNION</summary>

### Struct

- Trong ngôn ngữ lập trình C, struct là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. 

- Struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.

```c
#include <stdio.h>

/* Cách khai báo 1*/
// struct Point
// {
//     int x;
//     int y;
// }

// struct Point p1, p2, p3; // cách này khi khai báo phải có struct ở trước
/* Cách khai báo 2*/
typedef struct 
{
   int x;
   int y; 
} Point;

Point p1, p2, *p3;

int main(int argc, char const *argv[])
{
    p1.x = 2;
    p1.y = 3;

    p3->x = 4;
    return 0;
}
```
- Đối tượng thuộc lớp truy cập đến thành viên struct, toán tử `.`

- Con trỏ truy cập đến thành viên struct, toán tử `->`

#### Data alignment

- Địa chỉ bắt đầu: chia hết cho sizeof(kiểu dữ liệu)

```c
double (8 byte): 0x00, 0x08, 0x1f,...
int32_t, uint32_t, int, float (4 byte): 0x00, 0x04, 0x08,..
int16_t, uint16_t (2 byte): 0x00, 0x02, 0x04,...
char, int8_t, uint8_t (1 byte): 0x00, 0x01,..
```

#### Data padding

- Byte trống, ô địa chỉ không sử dụng, được thêm vào khi phân vùng nhớ

#### Kích thước của 1 struct

- Số lượng byte được cấp tính theo kiểu dữ liệu có kích thước lớn nhất trong struct đó.

Ví dụ 1:
 
 ```c
 typedef struct 
{                        // cấp phát (1 lần 4 byte)       sử dụng         dư
    int var1;   // 4        0x00 - 0x07                   0x00 - 0x03       0x04 - 0x07            
    char var2;  // 1                                      0x04              0x05 - 0x07
    char var3;  // 1                                      0x05              0x06 - 0x07: 2 padding
    float var4; // 4        0x08 - 0x0f                   0x08 - 0x0b       0x0c - 0x0f
    double var5;// 8        0x10 - 0x17                    

} Point

 ```

Ví dụ 2:

```c
typedef struct
{
    uint8_t var1[9];   //1  9
    uint32_t var2[2];  //4  8
    uint16_t var3[10]; //2  20
} frame;
```
- data alignment: cấp 1 lần 4 byte địa chỉ

- 0x00 - 0x03: lưu 4 phần tử mảng var1

- 0x04 - 0x07: lưu 4 phần tử tiếp theo của var1

- 0x08 - 0x0B: lưu phần tử 9 của var1, 3 padding

- 0x0C - 0x0F: var2 [0]

- 0x10 - 0x13: var2 [1]

- 0x14 - 0x17: var2[0] , var2[1]

- .....

📌 Cần cấp 40 byte (using 39, 1 padding)

- Kích thước: tổng các kích thước của các thành phần và padding

- Những thành phần có địa chỉ riêng biệt

### Union

- Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó.

-  Trong một thời điểm, chỉ một thành viên của union có thể được sử dụng.
-  

-  Kích thước union = kích thước lớn nhất của thành viên

Ví dụ:

```c
#include <stdio.h>
#include <stdint.h>

typedef union 
{
    uint8_t var1;  //1  3 padding
    uint32_t var2; //4  0 padding
    uint16_t var3; //2
} frame;

int main(int argc, char const *argv[])
{
    frame data;

    data.var1 = 5;
    data.var2 = 10;

    printf("var1: %d", data.var1); 
    printf("var2: %d", data.var1);
}
```

📌 Vấn đề khi sử dụng chung vùng nhớ
```c
  data.var2 = 4294967290; //0b 11111111 11111111 11111111 11111010
                                 0x03     0x02     0x01     0x00
    
    /*
    data.var1 = 11111010
    data.var3 = 11111111 11111010
    */
```

### Ứng dụng

- Struct: Viết thư viện, cấu hình, tính năng,..
- Kết hợp struct và union trong việc truyền dữ liệu của 2 vi điều khiển

![alt text](struct1.png)

![alt text](struct2.png)

```c
typedef union {
    struct {
        uint8_t id[2];
        uint8_t data[4];
        uint8_t check_sum[2];
    } data;

    uint8_t frame[8];

} Data_Frame;

```
- Khai báo biến sao cho tránh padding

- Struct lồng vào union, chỉ dùng 1 địa chỉ, 1 trong 3 thành phần thay đổi thì thành phần truyền đi frame sẽ được cập nhật

- Chuyển số thành chuỗi

```c
int main(int argc, char const *argv[])
{
    Data_Frame transmitter_data;
    
    strcpy(transmitter_data.data.id, "10");
    strcpy(transmitter_data.data.data, "1234");
    strcpy(transmitter_data.data.check_sum, "70");

        Data_Frame receiver_data;
    strcpy(receiver_data.frame, transmitter_data.frame);
    
    
    return 0;
}
```
- Debug truyền và nhận dữ liệu
![alt text](debug.png)

</details>

<details>
<summary>LESSON 8: MEMORY LAYOUT</summary>

</details>

<details>
<summary>LESSON 9: STACK - QUEUE</summary>

</details>










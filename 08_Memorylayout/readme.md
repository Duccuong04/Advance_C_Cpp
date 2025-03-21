# Memory layout

- Chương trình main.exe ( trên window), main.hex ( nạp vào vi điều khiển) được lưu ở bộ nhớ SSD hoặc FLASH. 

- Khi nhấn run chương trình trên window ( cấp nguồn cho vi điều khiển) thì những chương trình này sẽ được copy vào bộ nhớ RAM để thực thi.

![alt text](images/memo.png)

## **1. Text segment (Code segment)**

- Chứa mã máy (lệnh thực thi), nơi mà program counter sẽ trỏ tới để thực thi câu lệnh

- Quyền truy cập: read-only

- Dùng để lưu:

Các biến const (toàn cục)

Chuỗi hằng

```c
#include <stdio.h>

const int a = 10;
char arr[] = "Hello";  // mảng kí tự
char *arr1 = "Hello";  // chuỗi hằng
int b = 0;
int *ptr = &b;

int main() {
   

    printf("a: %d\n", a);

    arr[3] = 'W';
    printf("arr: %s", arr);

  //  arr1[3] = 'E';
    printf("arr1: %s", arr1);

    
    return 0;
}

```

Hàm

```c
#include <iostream>

void myFunction() {  
    std::cout << "This function is in the .text section." << std::endl;
}

int main() {
    myFunction();  // Gọi hàm, thực thi mã trong .text
    return 0;
}
```

## **2. Initialized Data Segment (Dữ liệu Đã Khởi Tạo)**

- Chứa các biến toàn cục được khởi tạo với giá trị khác 0.

- Chứa các biến static (global + local) được khởi tạo với giá trị khác 0.

- Quyền truy cập: đọc và ghi

- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.

```c
#include <stdio.h>

int a = 10;
double d = 20.5;

static int var = 5;

void test()
{
    static int local = 10;
}


int main(int argc, char const *argv[])
{  
    a = 15;
    d = 25.7;
    var = 12;
    printf("a: %d\n", a);
    printf("d: %f\n", d);
    printf("var: %d\n", var);



    return 0;
}

```

### Lưu ý với struct

Khi khởi tạo struct với các biến thành viên, các biến này vẫn nằm vùng bss, cho đến khi gọi struct thì mới được cấp vùng nhớ tại data

```c
typedef struct{
  int a;  
  int b;
}data;
static data dt = {23,12}; // 2 member a và b của struct data lúc này mới được cấp phát vùng nhớ ở data segment
```
## **3. Uninitialized Data Segment (BSS, Dữ liệu Chưa Khởi Tạo)**

- Chứa các biến toàn cục khởi tạo với giá trị bằng 0 hoặc không gán giá trị.

- Chứa các biến static với giá trị khởi tạo bằng 0 hoặc không gán giá trị.

- Quyền truy cập: đọc và ghi

- Tất cả các biến sẽ được thu hồi sau khi chương trình kết thúc.

Ví dụ:

```c
typedef struct 
{
    int x;
    int y;
} Point_Data;

Point_Data p1 = {5, 0};

Point_Data p2;

Point_Data p3 = {0, 0};
```

- `Point_Data p1 = {5, 0};`, p1 ở data ->thành viên x,y ở data -> x được khởi tạo giá trị = 5, y = 0 (y vẫn ở data)

- `Point_Data p2;`, p2,x,y: bss

- `Point_Data p3 = {0, 0};`: khởi tạo bằng 0 -> bss

📌 Lưu ý:

`const int a = 0; hằng số toàn cục`, tùy vào trình biên dịch MinGW gcc g++: rdata (read - only data) - text (MacOS clang)

```c
	.file	"text.c"
	.text
	.globl	a
	.section .rdata,"dr"
	.align 4
```

- `.text`, ghi địa chỉ thực thi câu lệnh vào text, từ `.global` cấp phát địa chỉ
- `char *ptr = "Hello";`, rdata - text. Nếu cố tình thay đổi `ptr[1] = 'a';` -> báo lỗi hoặc không tùy vào trình biên dịch


- `*ptr = NULL` // bss

## **4. Stack**

- Chứa các biến cục bộ (trừ static cục bộ), tham số truyền vào.

- Hằng số cục bộ, có thể thay đổi thông qua con trỏ.

Quyền truy cập: đọc và ghi, nghĩa là có thể đọc và thay đổi giá trị của biến trong suốt thời gian chương trình chạy.

- Sau khi ra khỏi hàm, sẽ thu hồi vùng nhớ.

**- Biến hằng số cục bộ nằm ở Stack (read - write), thay đổi thông qua con trỏ, biến hằng số toàn cục thì không thể thay đổi
**
```c
#include <stdio.h>

int *ptr = NULL;

void test()
{
    const int c = 10; // 0xf4: stack

    ptr = &c;
    *ptr = 20;

    printf("%d", c);
    
    char *str = "hello";

}
```

## **5. Heap**

- Cấp phát tĩnh: `char str[5]` cố định kích thước mảng (sau compile time) -> gây lãng phí bộ nhớ hoặc không đủ bộ nhớ để lưu trữ trong 1 số trường hợp -> sử dụng cấp phát tĩnh, thay đổi kích thước trong runtime

Cấp phát động:

- Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.

- Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.

- Các hàm như `malloc(), calloc(), realloc(), và free()` được sử dụng để cấp phát và giải phóng bộ nhớ trên heap. (thư viện stdlib)

#### malloc()

- cú pháp: void* malloc(size_t size)

- cấp phát vùng nhớ dựa trên kích thước chỉ định

- phải dùng con trỏ để quản lý vùng nhớ vừa được cấp phát và mặc định trỏ tới địa chỉ đầu tiên trong vùng nhớ

- địa chỉ con trỏ có thể nằm ở Stack/Data/Bss, nhưng địa chỉ nó trỏ tới là Heap

- kích thước chỉ định: phụ thuộc số lượng phần tử và kiểu dữ liệu từng phần tử

- kiểu tra về là void* nên cần phải ép kiểu

- giá trị khởi tạo cho từng byte địa chỉ là giá trị rác (không khởi tạo giá trị)

- thu hồi thủ công (thông qua hàm free)

- Nếu không thu hồi thì có thể không còn đủ địa chỉ để cấp phát (memory leak)

- tìm kiếm địa chỉ khác để cấp phát, con trỏ ptr tro tới vị trí bất kì -> sau khi thu hồi nên gán về NULL

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
int a = 10;

uint16_t *ptr = &a; // data

double *ptr = NULL; // bss
*/
int main(int argc, char const *argv[])
{

   
    uint16_t *ptr = NULL;

    int size;

    scanf("%d", &size);

    ptr = (uint16_t* )malloc(size * sizeof(uint16_t));
    /*
    -  cấp phát động theo số lượng phần tử và kiểu dữ liệu từng phần tử
    - ép kiểu để đọc đúng dữ liệu tại từng phần tử
    */
   for(int i = 0; i < size; i++)
   {
    printf("addr %d: %p - value: %d\n", i, ptr+i, *(ptr+i));
   }
      
    free(ptr); // thu hồi vùng nhớ
    return 0;
}

```

Output: mang giá trị rác

```c
5
addr 0: 000002134209DEF0 - value: 65
addr 1: 000002134209DEF2 - value: 65
addr 2: 000002134209DEF4 - value: 66
addr 3: 000002134209DEF6 - value: 81
addr 4: 000002134209DEF8 - value: 107
```
#### realloc()

- thay đổi kích thước vùng nhớ mà đã được cấp phát bởi malloc() hoặc calloc()

- giữ dữ liệu cũ, phần mở rộng không khởi tạo

- thu hồi thủ công (thông qua hàm free)

`ptr = (uint16_t* )realloc(ptr, 10 * sizeof(uint16_t));`

- cách thu hồi thứ 2

```c
for(int i = 0; i < 10; i++)
{
    ptr[i] = 0;
}
```
-> giá trị trong ô địa chỉ = 0, lần cấp phát tiếp theo trình biên dịch vẫn có thể lấy

#### So sánh calloc() malloc() & realloc()

***malloc()***

`void* malloc(size_t size);`

**Chức năng:** 

- Cấp phát một vùng nhớ trên heap có kích thước `size` byte

- Không khởi tạo giá trị cho vùng nhớ (giữ nguyên dữ liệu rác cũ trong bộ nhớ)

- Ép kiểu con trỏ về kiểu dữ liệu mong muốn

`int* arr = (int*)malloc(5 * sizeof(int)); // cấp phát mảng 5 phần tử int `

***calloc()***

**Chức năng:** 

- Cấp phát bộ nhớ trên heap cho `count` phần tử, mỗi phần tử có kích thước `size` byte.

- Khác với malloc(), calloc() sẽ khởi tạo tất cả các byte trong vùng nhớ được cấp phát về 0.

`int* arr = (int*)calloc(5, sizeof(int)); // Cấp phát và khởi tạo 5 phần tử int = 0
`

***realloc()***

**Chức năng:**

- Mở rộng vùng nhớ động mà không mất dữ liệu cũ (thay đổi kích thước của vùng nhớ đã được cấp phát trước đó.

`int* arr = (int*)malloc(5 * sizeof(int));`
`arr = (int*)realloc(arr, 10 * sizeof(int)); // Mở rộng lên 10 phần tử`

| Đặc điểm              | malloc()              | calloc()                     | realloc()                        |
|----------------------|----------------------|-----------------------------|---------------------------------|
| **Chức năng**        | Cấp phát bộ nhớ       | Cấp phát và khởi tạo bộ nhớ  | Điều chỉnh kích thước bộ nhớ   |
| **Số lượng tham số**  | 1 (`size`)           | 2 (`count, size`)           | 2 (`ptr, size`)                |
| **Khởi tạo giá trị**  | Không (dữ liệu rác)  | Có (gán toàn bộ bằng 0)     | Không thay đổi giá trị cũ, có thể mở rộng hoặc thu nhỏ |
| **Trả về**           | Con trỏ vùng nhớ mới hoặc `NULL` nếu thất bại | Con trỏ vùng nhớ mới hoặc `NULL` nếu thất bại | Con trỏ vùng nhớ mới hoặc `NULL` nếu thất bại |
| **Khi cấp phát thất bại** | Trả về `NULL` | Trả về `NULL` | Giữ nguyên vùng nhớ cũ nếu thất bại |
| **Ứng dụng**        | Khi cần cấp phát một vùng nhớ động | Khi cần cấp phát và khởi tạo vùng nhớ về 0 | Khi cần thay đổi kích thước vùng nhớ đã cấp phát |

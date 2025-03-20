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


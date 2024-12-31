### Goto

- goto là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm.

```c
goto label: 
.....
label:
    // Dòng lệnh được chuyển đến

```

- label là một tên đặt trước dấu :

- Khi chương trình gặp lệnh goto label, nó sẽ nhảy đến nhãn [label] tương ứng và thực thi các dòng lệnh từ đó

- Chỉ nhảy cục bộ

### Setjmp

- Là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp.

- Loại bot hạn chế chỉ nhảy trong hàm main của `goto`

```c
#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception;

void display()
{
    int x = 0;
}

int main(int argc, char const *argv[])
{
    exception = setjmp(buf);

    if(!exception)
    {
        printf("Exception = 0\n");
    }
    else if(exception == 1)
    {
        printf("Exception = 1\n");
    }
    else
    {
        printf("Exception # 0,1\n");
    }

    longjmp(buf, 2);
    
    return 0;
}

```

- Ở lần khởi tạo đầu tiên, hàm `setjmp(buf)` trả về 0, những lần khởi tạo sau trả về giá trị khác 0

- Câu lệnh `exception = setjmp(buf)` lưu trữ vị trí hiện tại,lưu địa chỉ con trỏ PC đang trỏ tới, kiểu `jmp_buf` là 1 mảng được sử dụng để lưu trữ trạng thái (program counter, thanh ghi khác,...)

`longjmp(buf, 1)`, khi thực thi câu lệnh này, program counter sẽ nhảy đến hàm `setjmp(buf)`

- 2 tham số truyền vào:
buf: vị trí `setjmp(buf)`; `1` giá trị trả về của `setjmp(buf)`


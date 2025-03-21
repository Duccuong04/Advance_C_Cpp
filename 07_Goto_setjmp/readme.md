# Goto

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

# Setjmp

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

## Kiểu dữ liệu jmp_buf

📌 jmp_buf về cơ bản là một mảng (array) hoặc cấu trúc (structure) nội bộ được định nghĩa trong thư viện <setjmp.h>. Nó lưu trữ các thông tin quan trọng về trạng thái của chương trình tại thời điểm gọi setjmp(), bao gồm:

- Giá trị của con trỏ stack (Stack Pointer - SP)

- Giá trị của con trỏ lệnh (Instruction Pointer - IP hoặc Program Counter - PC)

- Giá trị của thanh ghi CPU (Register values)

- Trạng thái của bộ nhớ (context switching information)

Cách định nghĩa của jmp_buf có thể khác nhau tùy vào hệ thống và trình biên dịch, nhưng về bản chất, nó giúp chương trình có thể tiếp tục thực thi từ một điểm đã lưu trước đó bằng cách sử dụng longjmp().

📌 Sử dụng jmp_buf

Cần hai hàm chính để làm việc với jmp_buf:

`setjmp(jmp_buf env)`

- Lưu trạng thái hiện tại của chương trình vào env.

- Trả về 0 khi được gọi lần đầu tiên.

- Khi longjmp() được gọi, setjmp() sẽ trả về một giá trị khác 0.

`longjmp(jmp_buf env, int val)`

- Nhảy trở lại vị trí trước đó đã lưu bằng setjmp(env).

- setjmp(env) sẽ trả về giá trị val (khác 0).

# Exception Handling

- Xử lý ngoại lệ (Exception Handling) là một cơ chế trong lập trình giúp phát hiện và xử lý các lỗi hoặc tình huống bất thường xảy ra trong quá trình thực thi chương trình, giúp chương trình hoạt động ổn định và không bị dừng đột ngột.

## Exception 

- Ngoại lệ là những lỗi hoặc sự kiện không mong muốn xảy ra trong quá trình thực thi chương trình, chẳng hạn như:

- Chia một số cho 0 (division by zero).

- Truy cập mảng ngoài phạm vi (out of bounds array access).

- Truy xuất con trỏ null (null pointer dereference).

- Lỗi khi mở hoặc đọc tập tin (file not found).

- Lỗi cấp phát bộ nhớ (bad allocation).

## Handling

try: Định nghĩa một khối lệnh có thể phát sinh lỗi.

catch: Xử lý ngoại lệ nếu có lỗi xảy ra.

throw: Ném ra một ngoại lệ khi xảy ra lỗi.

```c
try
{
    // Khối lệnh có thể phát sinh lỗi
}
catch (loại_ngoại_lệ_1)
{
    // Xử lý ngoại lệ loại 1
}
catch (loại_ngoại_lệ_2)
{
    // Xử lý ngoại lệ loại 2
}
catch (...)
{
    // Xử lý tất cả các ngoại lệ khác
}

```

## So sánh try cath throw >< Assert

| Tiêu chí              | try-catch-throw                          | assert                                      |
|----------------------|------------------------------------|--------------------------------|
| **Mục đích**         | Xử lý lỗi trong runtime           | Kiểm tra điều kiện trong debug |
| **Thời điểm hoạt động** | Khi chương trình đang chạy (runtime) | Khi debug (thường bị tắt ở chế độ release) |
| **Hậu quả khi gặp lỗi** | Chương trình có thể tiếp tục chạy | Chương trình dừng ngay lập tức |
| **Loại lỗi xử lý**   | Lỗi không mong muốn trong runtime (chia cho 0, truy cập mảng ngoài phạm vi...) | Kiểm tra giả định đúng trong logic |
| **Có thể phục hồi không?** | Có, có thể bắt và xử lý lỗi | Không, chương trình dừng luôn |
| **Ví dụ sử dụng**    | Kiểm tra lỗi nhập liệu, xử lý ngoại lệ trong hệ thống lớn | Kiểm tra điều kiện đầu vào của hàm khi debug |

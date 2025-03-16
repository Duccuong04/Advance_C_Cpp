# Lambda

- Là hàm chỉ sử dụng 1 lần hay nhiều lần (tùy vào cách sử dụng) trong chương trình nhưng chỉ trong cục bộ hàm khai báo

- Có thể sử dụng trực tiếp hoặc gán cho biến nếu muốn trích xuất hàm

- Khai báo cục bộ trong 1 hàm khác.

- Cú pháp:

```cpp
[capture] (parameters) -> <return_type>
{
    // function body
}

[capture] (parameters)
{
    // function body
}
```
parameters: danh sách các tham số truyền vào của lambda (giống function).

return_type:

Kiểu trả về của lambda.
Nếu không chỉ định, kiểu trả về sẽ được suy diễn.
function body: logic xử lý, câu lệnh.

- Ví dụ:

```c
      // định nghĩa lambda và gán cho biến
    auto func = []()
    {
        cout << "Hello" << endl;;
    };

    func();

    // định nghĩa lambda và gọi trực tiếp
    []()
    {
        cout << "Hello, lambda";
    }();
```

- Lambda được định nghĩa cục bộ trong hàm main

- Gọi thông qua biến, có thể gọi nhiều lần

- Gọi trực tiếp, chỉ được gọi 1 lần

```c
// capture: cho biết cách sử dụng các biến xung quanh lambda

// Không sử dụng bất kỳ biến nào
[]()

// Chỉ định biến cụ thể (x), truyền giá trị, read-only
[x]()

// Chỉ định biến cụ thể (x, y)
[x, y]()

// Chỉ định biến x, tham chiếu, read-write
[&x]()

// Chỉ định biến x và y, tham chiếu
[&x, &y]()

// Chỉ biến x theo tham chiếu, y truyền giá trị
[&x, y]()

// Sử dụng tất cả biến xung quanh, truyền giá trị
[=]()

// Sử dụng tất cả biến xung quanh, tham chiếu
[&]()

// Tất cả biến xung quanh theo tham chiếu, ngoại trừ biến x theo giá trị
[&, x]()

// Tất cả biến xung quanh theo giá trị, ngoại trừ biến x theo tham chiếu
[=, &x]()

```

# Namespace

- Trong C/C++, khai báo các hàm/ biến cùng tên trong 1 phạm vị -> xung đột -> lỗi

- Namespace là cách nhóm các đối tượng như biến, hàm, class,... vào một không gian tách biệt.

- Namespace được sử dụng với mục đích là để tránh xung đột tên khi có các định danh giống nhau được khai báo trong các phần của chương trình hoặc các thư viện khác nhau.

- Cú pháp 

```c
namespace <name_of_namespace>

{

}
```

-> gọi từ các vùng khác nhau nên không lỗi, mặc dù cùng tên

**Đặc điểm**

1. Cho phép nhiều namespace lồng vào nhau -> mỗi lần truy xuất dữ liệu phải dùng nhiều toán tử :: để đi qua từng namespace (A::C::D)

2. Cho phép Namespace mở rộng -> có thể khai báo namespace cùng tên -> tự động gộp lại thành 1 nếu cùng tên

## Từ khóa using

- Rút gọn code vì không cần dùng toán tử :: khi truy xuất dữ liệu bên trong namespace

- Chỉ nên dùng khi biến/ hàm trong namespace là duy nhất

## std

- Namespace tiêu chuẩn

- Đã định nghĩa sẵn các hàm cin, cout, endl;....

- Có thể mở rộng

```c

namespace std;
{
    struct
    {
        int x;
        double y;
    } Point 
}
```
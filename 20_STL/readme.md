# Standard Template Library

- Là một thư viện trong ngôn ngữ lập trình C++ cung cấp một tập hợp các template classes và functions để thực hiện nhiều loại cấu trúc dữ liệu và các thuật toán phổ biến.

***Container***

- Một container là một cấu trúc dữ liệu chứa nhiều phần tử theo một cách cụ thể. STL cung cấp một số container tiêu biểu giúp lưu trữ và quản lý dữ liệu. 

## 1. Vector

```c
	Một số method của vector:

at(): Truy cập vào phần tử của vector
size(): Trả về kích thước của vector
resize(): Thay đổi kích thước của vector
begin(): Địa chỉ của phần tử đầu tiên của vector
end(): Địa chỉ của phần tử cuối cùng của vector
push_back(): Thêm phần tử vào vị trí cuối của vector

```
- Là một mảng động, tức là có khả năng thay đổi kích thước một cách linh hoạt.

- Truy cập ngẫu nhiên: Việc truy cập các phần tử của vector có thể được thực hiện bằng cách sử dụng chỉ số.

- Hiệu suất chèn và xóa: Chèn và xóa phần tử ở cuối vector có hiệu suất tốt. Tuy nhiên, chèn và xóa ở vị trí bất kỳ có thể đòi hỏi di chuyển một số phần tử.

**Ví dụ**

📌 Khai báo 1 vector và các phần tử

`vector <int> arr1 = {2,5,7,4,9};`: khai báo đối tượng arr1 (mảng động), các phần tử có kiểu dữ liệu int (sử dụng template)

📌 Trích xuất dữ liệu trong 1 vector

-  Sử dụng method `size()` để biết được số lượng phần tử trong vector

- `resize()`: thay đổi kích cỡ vector `vec.resize(7)` -> cấp phát 28 byte vùng nhớ

- `at()`: đọc và ghi đè dữ liệu, `arr1.at(10) = 1` -> ghi đè dữ liệu phần tử thứ 10 trong vector

```c
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << "Value: " << arr1[i] << endl;
        // Cách 2
        // cout << "Value: " << arr1.at(i) << endl;
    }

    // Cách 3: dùng vòng lặp for cải tiến

    for(item : arr1)
    {
        cout << item;
    }
```

- **Vòng lăp for cải tiến** (range based for loop): mỗi lần duyệt qua vector arr1, item mang giá trị của phần tử đầu tiên trong vector

📌 Cách 4: *iterator*, thao tác với dữ liệu

- Bên trong iterator đã có con trỏ được khai báo

```c
Template <typename T>
class Vetor
{
    public:
    class Iterator
    {
        private:
        T* ptr;
    };
};
```

```c
// Cách 4: Duyệt mảng bằng iterator
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int>::iterator it; // khai báo đối tượng
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *it << " "; // it là con trỏ -> giải tham chiếu để lấy giá trị
    }

    return 0;
}

/*
 * vec.begin(): lấy địa chỉ phần tử đầu tiên      0x01
 * vec.end()  : lấy địa chỉ sau phần tử cuối cùng 0x14
 */

```

📌 Khai báo 1 vector bằng hàm `push back()`

- `push back()`: Thêm phần tử vào cuối vector

- `insert(...,...)`: thêm phần tử tại vị trí bất kì, truyền vào *địa chỉ*

- `pop_back()`: Xóa phần tử cuối cùng trong vector

- `vec.erase(vec.begin());`: xóa phần tử tại vị trí bất kì

- `vec.erase(vec.begin(), vec.begin()+2);`: xóa nhiều phần tử 1 lúc

```c
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;

    cout << "Boot process" << endl;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);

    vec.insert(vec.begin(), 40);
    vec.insert(vec.end(), 15);
    vec.insert(vec.end()-1, 10);

    for(auto item : vec)
    {
        cout << item << " ";
    }

    cout << "Pop process" << endl;
    vec.pop_back();
    vec.erase(vec.begin());
    vec.erase(vec.begin()+1);
    vec.erase(vec.end()-1);

    for(auto item : vec)
    {
        cout << item << " ";
    }

    cout << endl;
    return 0;
}


```

## 2. List

## 3. Map


# 1. Text

- lưu mã máy (địa chỉ PC trỏ tới thực thi)

- chỉ đọc và thực thi

- compiler Clang:

    + hằng số toàn cục

    + chuỗi hằng

# 2. Data

- biến khởi tạo giá trị khác 0:

    + biến toàn cục

    + static (toàn cục + cục bộ)

- đọc, ghi

- compiler MinGW(gcc, g++):

    + hằng số toàn cục

    + chuỗi hằng

    + chỉ đọc (rdata)

# 3. BSS

- biến khởi tạo giá trị bằng 0 hoặc không khởi tạo giá trị:

    + biến toàn cục

    + static (toàn cục + cục bộ)

- đọc, ghi

# 4. Stack

- biến cục bộ, bao gồm cả hằng số cục bộ nhưng ngoại trừ static cục bộ

- tham số truyền vào của hàm

- đọc, ghi

- hằng số cục bộ có thể thay đổi giá trị thông qua con trỏ

- địa chỉ các biến sẽ bị thu hồi khi kết thúc hàm (tự động)

- Memory Leak: đệ quy

- Last In, First Out

# 5. Heap

- Sử dụng để cấp phát động:

    + C: malloc(), calloc(), realloc(), free()

    + C++: new, delete

## Cấp phát tĩnh và cấp phát động khác nhau??

## malloc()

- cú pháp: void* malloc(size_t size)

- cấp phát vùng nhớ dựa trên kích thước chỉ định

- phải dùng con trỏ để quản lý vùng nhớ vừa được cấp phát và mặc định trỏ tới địa chỉ đầu tiên trong vùng nhớ

- địa chỉ con trỏ có thể nằm ở Stack/Data/Bss, nhưng địa chỉ nó trỏ tới là Heap

- kích thước chỉ định: phụ thuộc số lượng phần tử và kiểu dữ liệu từng phần tử

- kiểu tra về là void* nên cần phải ép kiểu

- giá trị khởi tạo cho từng byte địa chỉ là giá trị rác (không khởi tạo giá trị)

- thu hồi thủ công (thông qua hàm free)

- Nếu không thu hồi thì có thể không còn đủ địa chỉ để cấp phát (memory leak)

## realloc()

- thay đổi kích thước vùng nhớ mà đã được cấp phát bởi malloc() hoặc calloc()

- giữ dữ liệu cũ, phần mở rộng không khởi tạo

- thu hồi thủ công (thông qua hàm free)

## Thu hồi vùng nhớ cấp phát động

- Cách 1: hàm free

- Cách 2: sử dụng realloc() và gán giá trị cho các địa chỉ bằng 0
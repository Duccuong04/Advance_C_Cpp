## Pthread
- Với các lập trình thông thường trong C, các câu lệnh, hàm thường được gọi ra theo cơ chế polling (tuần tự) 

- Thực hiện task1 thì mới thực hiện task 2 -> thư viện pthread cung cấp các hàm để có thể mô phỏng 2 tác vụ thực thi song song với nhau (bản chất của RTOS trong embedded)

![alt text](image.png)

- Các câu lệnh khai báo biến, gọi hàm được cấp địa chỉ trong memory layout -> đến câu lệnh nào thì con trỏ PC trỏ tới để thực thi

- Bản chất của đa lường cũng là tuần tự nhưng phân chia thời gian ở các task

### 1. Khái niệm

- **Thread**: đơn vị nhỏ nhất trong 1 tiến trình, mỗi tiến trình có nhiều luồng khác nhau

### 2. Thư viện Pthread

- Cung cấp các hàng để chạy đa luồng, nhiều tác vụ cùng lúc

- Đa nhiệm: xử lý nhiều tác vụ khác nhau

- Đa luồng: chia thành nhiều luồng, mỗi luồng lại xử lý các đa nhiệm khác nhau

- Đa lõi (bộ xử lý có nhiều nhân): nhiều lõi trên 1 CPU. Một lõi CPU không thực sự xử lý song song đa nhiệm hoặc luồng. Chúng lên lịch trình để chuyển đổi giữa các task mỗi mili giây -> tạo cảm giác chạy song song nhiều ứng dụng cùng lúc.

### 2.1. Hàm pthread_create

- Khởi chạy 1 thread và chỉ định thực hiện nhiệm vụ     

`pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg)`

`pthread_create(&t1, NULL, task1, NULL);`

- Các tham số truyền vào

    - 1: con trỏ kiểu pthread_t, tên luồn

    - 2: thuộc tính của thread, đặt là NULL nếu dữ liệu thuộc tính mặc định (độ ưu tiên... RTOS)

    - 3: địa chỉ hàm (nhiệm vụ) muốn luồng thực thi

    - 4: tham số truyền vào trong hàm ở 3

### 2.2. Hàm chờ một thread kết thúc

- Chờ 1 luồng kết thúc

`int pthread_join(pthread_t t, void **res)`

    - 1: ID của thread muốn chờ

    - 2: biến lưu trữ kết quả trả về từ 1 thread/ NULL

```c
pthread_t t1; // luồng 1
    pthread_t t2; // luồng 2
    pthread_t t3; // luồng 3

    char *ptr = "Hello\n";
   
    pthread_create(&t1, NULL, task1, NULL);
    pthread_create(&t2, NULL, task2, NULL);
    pthread_create(&t3, NULL, display, ptr);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
```
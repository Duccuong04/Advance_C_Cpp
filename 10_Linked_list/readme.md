### Linked List

📌 Mảng: các dữ liệu được chứa trong mảng có địa chỉ liền kề nhau, phải biết được số lượng phần tử trong mảng

📌 Linked list: 

- Linked list là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu.

- Gồm các node, không quan tâm đến số lượng node, mỗi node có địa chỉ ngẫu nhiên. Mỗi nút chứa một giá trị dữ liệu (con số, kí tự, chuỗi,...) và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.

- Khi khởi tạo, các con trỏ trong mỗi node mang giá trị NULL. Sau khi liên kết thì con trỏ mang địa chỉ của node tiếp theo (trừ node cuối cùng).

- Ưu điểm so với mảng: thêm, xóa phần tử dễ dàng hơn

📌 Lưu ý khi viết các hàm thao tác linked list

Thêm 1 node vào phía cuối

- Nếu sử dụng con trỏ first cấp 1: nếu danh sách liên kết chưa có node nào sẽ gây lỗi (do kết thúc hàm con trỏ first đã được giải phóng) -> dùng con trỏ cấp 2


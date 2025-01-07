### Stack

- Stack (ngăn xếp) là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 

- Các thao tác cơ bản trên stack bao gồm:

"push" để thêm một phần tử vào đỉnh của stack

"pop" để xóa một phần tử ở đỉnh stack.

"peek/top" để lấy giá trị của phần tử ở đỉnh stack.

Kiểm tra Stack đầy: top = size - 1

Kiểm tra Stack rỗng: top = -1

### Queue

- Cấu trúc dữ liệu FIFO (First in, First out)

- Các thao tác cơ bản trên hàng đợi bao gồm:

“enqueue” (thêm phần tử vào cuối hàng đợi)

“dequeue” (lấy phần tử từ đầu hàng đợi). 

“front” để lấy giá trị của phần tử đứng đầu hàng đợi.

“rear” để lấy giá trị của phần tử đứng cuối hàng đợi.

Kiểm tra hàng đợi đầy/rỗng.

Ban đầu queue rỗng thì front = rear = -1; thêm vào phần tử đầu tiên, front = rear = 0

Chỉ được thêm dữ liệu mới vào (enqueue) khi queue rỗng toàn bộ -> front, rear về lại vị trí ban đầu (không thể thêm phần tử mới kể cả khi phía trước có khoảng trống)

📌 Để khắc phục nhược điểm này của Linear Queue, sử dụng Circular Queue:

- Khi rear đạt tới size - 1 và không còn chỗ trống từ phía cuối, nếu front đã di chuyển (nghĩa là đã có các phần tử được dequeue), rear có thể "quay vòng" về vị trí 0 để tận dụng khoảng trống.

- Khi kiểm tra rỗng chỉ có 1 trường hợp

📌 Ứng dụng Queue: truyền bit dữ liệu
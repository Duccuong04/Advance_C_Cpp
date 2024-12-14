### Bit mask

📌 Để tối ưu hóa bộ nhớ khi khai báo biến trong C, ta khai báo thư viện `#include <stdint.h>`, một số kiểu dữ liệu trong thư viện
```c
/*
    int, int32_t, uint32_t: 4 byte
    int8_t, uint8_t: 1 byte
    int16_t, uint16_t: 2 byte
*/
```
📌 Bit mask một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái (thao tác trên bit).

Ví dụ:

```c
/*
    uint8_t PORT_A = 0b00001101 (1 byte)
    bit 0: Pin_A0
    bit 1: Pin_A1 
    bit 2: Pin_A2
    .
    .
    .
    bit 8: Pin_A8

    Thao tác trên cụm bit này -> bit mask -> tối ưu hóa bộ nhớ
*/
```
📌 Các toán tử bitwise

- `AND (&), OR(|), XOR(^), NOT(~)`

![alt text](bitwise.png)

Ví dụ:

```c
uint8_t A = 0b01001001;
uint8_t B = 0b11101111;
    /*
    ~A = 0b10110110;
    A&B = 0b01001001;
    A|B = 0b11101111;
    A^B = 0b10100110;
    */
```

- `Shift left (<<) và Shift right (>>)`: phép dịch bit
- Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
- Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).

Ví dụ:

```c
uint8_t A = 0b01001001;
uint8_t B = 0b11101111;
    A = A << 2; //0b00100100;
    B = B >> 3; //0b00011101; 
    // bit dấu chỉ có ý nghĩa khi số có dấu (-8)
```

📌 Ví dụ sử dụng bit mask

```c
include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)  0b00000001 << 0
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
0b00000001 << 1
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
    /*
    options = 0b00000000; features = &options;
    Giả sử cần bật tính năng HAT ở bit 2
    0b00000000 | 0b00000100 = 0b00000100
    */
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
    

    // Thêm các điều kiện kiểm tra cho các tính năng khác
}



int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```
- Sử dụng phép dịch bit và macro để khai báo các tính năng (tối ưu bộ nhớ)
- Dùng toán tử bit wise để bật tắt các tính năng mà không ảnh huởng đến tính năng khác, kiểm tra xem tính năng nào đã được bật.


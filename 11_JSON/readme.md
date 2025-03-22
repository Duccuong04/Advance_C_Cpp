**[Slide trình bày](https://docs.google.com/presentation/d/1DRcPVRLsyATXHllUukHlzCHDyrfTYpHc/edit#slide=id.p7)**


# Cấu trúc JSON (định dạng dữ liệu)

-  Định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.

- Cú pháp `key - value`

- Ngăn cách bởi dấu hai chấm

## 1. Lưu trữ dữ liệu

- Mỗi cặp key-value là 1 object

```c
{ 
  "name": "John Doe",
  "age": 30,
  "city": "New York",
  "isStudent": false,
  "grades": [85, 90, 78]
}
```
- Lưu trữ dưới dạng là 1 array, mỗi phần tử trong array gồm nhiều cặp key - value

- Key luôn là 1 chuỗi

- Value là bất kì kiểu nào (có thể là 1 cặp key - value (object) khác)

```c
[
  {
    "name": "John Doe",
    "age": 30,
    "city": "New York",
    "occupation": "Software Engineer",
    "isStudent": false
  },
  {
    "name": "Jane Smith",
    "age": null,
    "city": "Los Angeles",
    "contact": {
      "email": "jane.smith@example.com",
      "phone": "555-1234"
    }
  },
  {
    "name": "Bob Johnson",
    "age": 35,
    "city": "Chicago"
  },
  20, 3.14, "Hello World", true, null, [80, 70, 90]
]


Tên*
Tuổi: 
SDT*:
Địa chỉ*:
Nghề nghiệp: 

```

## 2. So sánh JSON với struct & union

| **Tiêu chí**       | **JSON**                                                   | **Struct**                                                |
|--------------------|-----------------------------------------------------------|----------------------------------------------------------|
| **Định nghĩa**     | Định dạng dữ liệu có cấu trúc theo dạng chuỗi văn bản     | Kiểu dữ liệu có cấu trúc trong ngôn ngữ lập trình C/C++  |
| **Quản lý bộ nhớ** | Linh hoạt, chỉ chứa các trường dữ liệu cần thiết          | Cấp phát bộ nhớ cố định cho tất cả thành viên, có thể gây lãng phí |
| **Hiệu suất**      | Chậm hơn do cần phân tích cú pháp (parsing)               | Nhanh hơn do truy cập trực tiếp vào bộ nhớ               |
| **Tính di động**   | Dễ dàng trao đổi giữa các hệ thống, nền tảng khác nhau    | Chủ yếu sử dụng trong cùng một chương trình hoặc hệ thống nhúng |
| **Ứng dụng thực tế** | Giao tiếp dữ liệu qua API, lưu trữ cấu hình, web service | Quản lý bộ nhớ thấp, giao tiếp giữa thiết bị và phần cứng |
| **Tính an toàn**   | Có thể chứa dữ liệu không xác định nếu không kiểm tra kỹ  | Được kiểm soát chặt chẽ trong bộ nhớ, an toàn hơn        |

## Ví dụ về JSON

- Khai báo chuỗi JSON đầu vào

`const char* json_str = "{ \"key\": \"value\" }";`

- Trong C/C++, một chuỗi ký tự được bao quanh bởi dấu ngoặc kép "...". Nếu trong chuỗi này có một dấu " thì nó phải được escape bằng ký tự \, tức là "\"" thay vì ". Điều này giúp trình biên dịch phân biệt đâu là phần nội dung chuỗi và đâu là ký hiệu đóng/mở chuỗi.

- Từng kí tự được chứa trong 1 địa chỉ riêng biệt

**1. Định nghĩa kiểu dữ liệu JSON**

*1.1. Xác định các loại dữ liệu có thể có trong JSON:*

JSON_NULL: Đại diện cho giá trị null.
JSON_BOOLEAN: Đại diện cho giá trị true hoặc false.
JSON_NUMBER: Đại diện cho số (số nguyên hoặc số thực).
JSON_STRING: Đại diện cho chuỗi.
JSON_ARRAY: Đại diện cho một mảng.
JSON_OBJECT: Đại diện cho một đối tượng JSON.

```c
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;
```

*1.2. Cấu trúc JSONValue, định nghĩa dữ liệu tương ứng với kiểu dữ liệu*

```c
[10, "hello", true, [1, 2, 3]]
values[0] -> số 10
values[1] -> chuỗi "hello"
values[2] -> giá trị boolean `true`
values[3] -> một `JsonValue` kiểu mảng chứa `[1, 2, 3]`
```

```c
typedef struct JsonValue {
    JsonType type;  // Kiểu dữ liệu của giá trị JSON
    union {
        int boolean; // Lưu trữ true (1) hoặc false (0)
        double number; // Lưu trữ số
        char *string; // Lưu trữ chuỗi (dạng con trỏ)
        struct {
            struct JsonValue *values; // Mảng các giá trị JSON
            size_t count; // Số lượng phần tử trong mảng
        } array;
        struct {
            char **keys; // Mảng các key (chuỗi) của object
            struct JsonValue *values; // Mảng các giá trị tương ứng
            size_t count; // Số lượng cặp key-value
        } object;
    } value;
} JsonValue;

```

- Xác định kiểu dữ liệu phù hợp với từng loại

- **Kiểu union:** với 3 thành viên boolean, number, string, array, object được dùng để gán giá trị cho dữ liệu json mà ta muốn và ở mỗi thời điểm sẽ chỉ có 1 thành viên được dùng và được xác định thông qua JsonType

- **union **giúp giảm bộ nhớ sử dụng bằng cách chỉ cấp phát không gian cho một kiểu duy nhất thay vì tất cả.

**array trong union**: giúp biểu diễn một mảng JSON dưới dạng một mảng động trong C. Mỗi phần tử trong values là một giá trị JSON (JsonValue), và count lưu số lượng phần tử hiện có.

**object trong union**

- Lưu trữ đối tượng object trong JSON, **count** là số cặp key - value

- **keys** là mảng bao gồm các con trỏ trỏ đến chuỗi, mỗi phần tử của mảng trỏ đến một chuỗi ký tự (tên của key).

- Vì key trong JSON là chuỗi động, ta sử dụng con trỏ char * để quản lý.
Dùng char ** nghĩa là một mảng chứa các con trỏ đến chuỗi.

**2. Hàm bỏ qua khoảng trắng**

```c
static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}
```

**3. Hàm chính phân tích chuỗi JSON**

```c
JsonValue *parse_json(const char **json) { 
    while (isspace(**json)) {
        (*json)++;
    }



    switch (**json) {
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
}
```

- Bỏ qua khoảng trắng

- Dựa vào kí tự đầu tiên, gọi hàm thích hợp để xử lý

- **json truy cập đến từng kí tự trong chuỗi

**4. Hàm kiểm tra chuỗi NULL**

```c
sonValue *parse_null(const char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}
```

- Kiểm tra chuỗi có bắt đầu bằng "null" không.

- Nếu có, cấp phát một JsonValue với type = JSON_NULL.

- Di chuyển con trỏ chuỗi JSON lên 4 ký tự (*json += 4) để trỏ đến địa chỉ của chuỗi tiếp theo

- Nếu không, trả về NULL.

**5. Hàm kiểm tra true/ flase**


```c
JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false; // value.boolean ở union
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}
```

**6. Hàm kiểm tra số**

- Hàm parse_number() được sử dụng để phân tích một số (number) từ chuỗi JSON. Nó kiểm tra xem chuỗi có bắt đầu bằng một số hợp lệ không, sau đó chuyển đổi số đó thành kiểu double và lưu vào một JsonValue.

```c
JsonValue *parse_number(const char **json) {
    skip_whitespace(json);
    char *end;


    double num = strtod(*json, &end);
    if (end != *json) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}
```

- Hàm trả về con trỏ đến `JsonValue`, chứa số vừa được phân tích

- Truyền vào `const char **json`, dùng con trỏ cấp 2 để có thể cập nhật vị trí con trỏ bên ngoài hàm

- Biến end là một con trỏ (char *) được sử dụng để xác định vị trí kết thúc của số sau khi được chuyển đổi từ chuỗi.

`double num = strtod(*json, &end); // double strtod(const char *str, char **endptr);`

- Biến end là một con trỏ (char *) được sử dụng để xác định vị trí kết thúc của số sau khi được chuyển đổi từ chuỗi.

| *json* đầu vào | *num* (số được đọc) | *end* trỏ đến |
|---------------|--------------------|--------------|
| `"123.45,"`  | 123.45              | `","`        |
| `"42abc"`    | 42                  | `"abc"`      |
| `"xyz"`      | Lỗi (`end == *json*`) | `"xyz"`      |

**7. Hàm `JsonValue *parse_object(const char **json)` phân tích cú pháp 1 đối tượng JSON từ chuỗi đầu vào**

***Cấp phát động bộ nhớ cho đối tượng JSON***

```c
JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
object_value->type = JSON_OBJECT;
object_value->value.object.count = 0;
object_value->value.object.keys = NULL;
object_value->value.object.values = NULL;

```

- Thiết lập kiểu (type = JSON_OBJECT) để đánh dấu rằng đây là một đối tượng JSON.

Khởi tạo các giá trị ban đầu:

count = 0: Số lượng cặp key-value trong đối tượng JSON.

keys = NULL: Chưa có khóa (key).

values = NULL: Chưa có giá trị (value).

***Duyệt qua các cặp key - value trong đối tượng***

1. `while(**json != '}' && **json != '\0'{`

- Duyệt chuỗi JSON cho đến khi gặp dấu } (kết thúc đối tượng) hoặc \0 (kết thúc chuỗi)

2. `JsonValue *key = parse_string(json);`: đọc một chuỗi (chuỗi key trong JSON)

***Đọc giá trị của key hiện tại***

`JsonValue *value = parse_json(json);`

***Lưu key - value vào đối tượng JSON***

```c

object_value->value.object.count++;
object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
object_value->value.object.values[object_value->value.object.count - 1] = *value;
free(value);

```

- Tăng count để ghi nhận số lượng cặp key-value.

- Cấp phát lại bộ nhớ (realloc) cho keys và values để chứa thêm một phần tử mới.

- Gán key vào keys và giá trị vào values.
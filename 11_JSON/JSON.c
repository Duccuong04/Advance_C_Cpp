#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Khai báo các loại dữ liệu có trong JSON
 */
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

/**
 * Định nghĩa dữ liệu tương ứng với kiểu dữ liệu
 */
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



JsonValue *parse_json(const char **json);

void free_json_value(JsonValue *json_value);

/**
 * Bỏ qua khoảng trắng
 */
static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

/**
 * Kiểu tra chuỗi NULL
 * 
 */
JsonValue *parse_null(const char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}

/**
 * parse booclean, number, string, array, object in JSON
 */
JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}

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

JsonValue *parse_string(const char **json) {
    skip_whitespace(json);


    if (**json == '\"') {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0') {
            (*json)++;
        }
        if (**json == '\"') {
            size_t length = *json - start; // 3
            char *str = (char *) malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';


            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}



JsonValue *parse_array(const char **json) {
    skip_whitespace(json);
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        while (**json != ']' && **json != '\0') {
            JsonValue *element = parse_json(json); // 70
            if (element) {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {
            (*json)++;
            return array_value;
        } else {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_object(const char **json) {
    skip_whitespace(json);
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;



        while (**json != '}' && **json != '\0') {
            JsonValue *key = parse_string(json);
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value) {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    } else {
                        free_json_value(key);
                        break;
                    }
                } else {
                    free_json_value(key);
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {
            (*json)++;
            return object_value;
        } else {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}

/**
 * Hàm phân tích chính
 * Bỏ qua khoảng trắng
 * Dựa vào kí tự đầu tiên, gọi hàm thích hợp để xử lý
 * **json truy cập đến từng kí tự trong chuỗi
 */
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

void free_json_value(JsonValue *json_value) {
    // Kiểm tra nếu json_value là NULL thì không cần giải phóng
    if (json_value == NULL) {
        return;
    }

    // Xử lý tùy theo loại dữ liệu của json_value
    switch (json_value->type) {
        case JSON_STRING:
            // Giải phóng bộ nhớ của chuỗi
            free(json_value->value.string);
            break;

        case JSON_ARRAY:
            // Lặp qua từng phần tử trong mảng và giải phóng
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            // Giải phóng bộ nhớ cấp phát cho danh sách các phần tử
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:
            // Lặp qua từng cặp key-value trong đối tượng JSON
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]); // Giải phóng khóa (key)
                free_json_value(&json_value->value.object.values[i]); // Giải phóng giá trị (value)
            }
            // Giải phóng danh sách các khóa và giá trị
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            // Các kiểu dữ liệu như JSON_NUMBER, JSON_BOOLEAN, JSON_NULL
            // không cần giải phóng bộ nhớ động nên không làm gì cả
            break;
    }
}



void test(JsonValue* json_value) {
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        // Nếu là đối tượng JSON, duyệt qua từng cặp key-value
        size_t num_fields = json_value->value.object.count;
        for (size_t i = 0; i < num_fields; ++i) {
            char* key = json_value->value.object.keys[i];
            JsonValue* value = &json_value->value.object.values[i];
            JsonType type = json_value->value.object.values[i].type;

            // Kiểm tra kiểu dữ liệu và in giá trị tương ứng
            if (type == JSON_STRING) {
                printf("%s: %s\n", key, value->value.string);
            } else if (type == JSON_NUMBER) {
                printf("%s: %f\n", key, value->value.number);
            } else if (type == JSON_BOOLEAN) {
                printf("%s: %s\n", key, value->value.boolean ? "True" : "False");
            } else if (type == JSON_OBJECT) {
                // Nếu giá trị là một đối tượng, gọi test() đệ quy để hiển thị
                printf("%s: \n", key);
                test(value);
            } else if (type == JSON_ARRAY) {
                // Nếu giá trị là một mảng, duyệt qua từng phần tử và hiển thị
                printf("%s: ", key);
                for (size_t j = 0; j < value->value.array.count; j++) {
                    test(&value->value.array.values[j]);
                }
                printf("\n");
            }
        }
    } else {
        // Nếu json_value là một giá trị đơn lẻ, hiển thị trực tiếp
        if (json_value->type == JSON_STRING) {
            printf("%s ", json_value->value.string);
        } else if (json_value->type == JSON_NUMBER) {
            printf("%f ", json_value->value.number);
        } else if (json_value->type == JSON_BOOLEAN) {
            printf("%s ", json_value->value.boolean ? "True" : "False");
        }
    }
}


/*
{
  "name": "John Doe",
  "age": 30.1234,
  "city": "New York",
  "isStudent": true,
  "grades": [85, 90, 78]
}
*/

void creat()
{
    JsonValue *json_str = (JsonValue*)malloc(sizeof(JsonValue));

    json_str->type = JSON_OBJECT;
    json_str->value.object.count = 5;

    json_str->value.object.keys = (char**)malloc(json_str->value.object.count * sizeof(char*));
    json_str->value.object.values = (JsonValue*)malloc(json_str->value.object.count * sizeof(JsonValue));

    // tạo cặp key-value 1
    json_str->value.object.keys[0] = "name";
    json_str->value.object.values[0].type = JSON_STRING;
    json_str->value.object.values[0].value.string = "John Doe";

    // tạo cặp key-value 2
    json_str->value.object.keys[1] = "age";
    json_str->value.object.values[1].type = JSON_NUMBER;
    json_str->value.object.values[1].value.number = 30.1234;

    // tạo cặp key-value 3

    // tạo cặp key-value 4

    // tạo cặp key-value 5
    json_str->value.object.keys[4] = "grades";
    json_str->value.object.values[4].type = JSON_ARRAY;
    json_str->value.object.values[4].value.array.count = 3;

    json_str->value.object.values[4].value.array.values = (JsonValue*)malloc(json_str->value.object.values[4].value.array.count * sizeof(JsonValue));
    json_str->value.object.values[4].value.array.values[0].type = JSON_NUMBER;

    // phần tử đầu tiên trong mảng
    json_str->value.object.values[4].value.array.values[0].value.number = 85;
}


int main(int argc, char const *argv[])
{
     // Chuỗi JSON đầu vào
    
    const char* json_str = "{"
                        "\"1001\":{"
                          "\"SoPhong\":3,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Nguyen Van A\","
                            "\"CCCD\":\"1920517781\","
                            "\"Tuoi\":26,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                              "\"Phuong_Xa\":\"Phuong 6\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Nguyen Van A\","
                            "\"2\":\"Nguyen Van B\","
                            "\"3\":\"Nguyen Van C\""
                          "},"
                          "\"TienDien\": [24, 56, 98],"
                          "\"TienNuoc\":30.000"
                        "},"
                        "\"1002\":{"
                          "\"SoPhong\":5,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Phan Hoang Trung\","
                            "\"CCCD\":\"012345678912\","
                            "\"Tuoi\":24,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"53 Le Dai Hanh\","
                              "\"Phuong_Xa\":\"Phuong 11\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Phan Van Nhat\","
                            "\"2\":\"Phan Van Nhi\","
                            "\"2\":\"Phan Van Tam\","
                            "\"3\":\"Phan Van Tu\""
                          "},"
                          "\"TienDien\":23.000,"
                          "\"TienNuoc\":40.000"
                        "}"
                      "}";
    

    // Phân tích cú pháp chuỗi JSON
    JsonValue* json_value = parse_json(&json_str);



   test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

       // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);
    
    

        //printf("test = %x", '\"');

       // hienthi(5);
    
    return 0;
}



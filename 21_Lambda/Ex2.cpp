#include <iostream>

using namespace std;

int main() {
    int x = 10, y = 20;
    
    // Không sử dụng bất kỳ biến nào
    auto lambda1 = []() { cout << "Lambda 1\n"; };
    
    // Chỉ định biến cụ thể (x), truyền giá trị (read-only)
    auto lambda2 = [x]() { cout << "Lambda 2: x = " << x << "\n"; };
    
    // Chỉ định biến cụ thể (x, y), truyền giá trị (read-only)
    auto lambda3 = [x, y]() { cout << "Lambda 3: x = " << x << ", y = " << y << "\n"; };
    
    // Chỉ định biến x, truyền tham chiếu (read-write)
    auto lambda4 = [&x]() { x += 5; cout << "Lambda 4: x = " << x << "\n"; };
    
    // Chỉ định biến x và y, truyền tham chiếu
    auto lambda5 = [&x, &y]() { x += 5; y += 10; cout << "Lambda 5: x = " << x << ", y = " << y << "\n"; };
    
    // Truyền x theo tham chiếu, y theo giá trị
    auto lambda6 = [&x, y]() { x += 5; cout << "Lambda 6: x = " << x << ", y = " << y << "\n"; };
    
    // Sử dụng tất cả biến xung quanh, truyền giá trị
    auto lambda7 = [=]() { cout << "Lambda 7: x = " << x << ", y = " << y << "\n"; };
    
    // Sử dụng tất cả biến xung quanh, truyền tham chiếu
    auto lambda8 = [&]() { x += 5; y += 10; cout << "Lambda 8: x = " << x << ", y = " << y << "\n"; };
    
    // Tất cả biến theo tham chiếu, ngoại trừ x theo giá trị
    auto lambda9 = [&, x]() { y += 10; cout << "Lambda 9: x = " << x << ", y = " << y << "\n"; };
    
    // Tất cả biến theo giá trị, ngoại trừ x theo tham chiếu
    auto lambda10 = [=, &x]() { x += 5; cout << "Lambda 10: x = " << x << ", y = " << y << "\n"; };

    // Gọi các lambda
    lambda1();
    lambda2();
    lambda3();
    lambda4();
    lambda5();
    lambda6();
    lambda7();
    lambda8();
    lambda9();
    lambda10();

    return 0;
}

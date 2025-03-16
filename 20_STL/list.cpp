#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    list<int> lst = {2, 5, 7}; // node 0,1,2

    lst.push_back(1);  // node 3
    lst.push_back(3);  // node 4
    lst.push_back(2);
    lst.push_back(7);
    lst.push_back(5);

    lst.push_front(15);

    cout << "Số lượng node: " << lst.size() << endl;

    // In danh sách liên kết
    for (int x : lst) {
        cout << x << " " << endl;
    }
    
    i = 0;

    list <int>::iterator it = lst.begin();
    
    for(it = lst.begin(); it!=lst.end(); it++)
    {
        cout << "Node " << i++ << ", Value: " << *it << endl;
    }

    i = 0;

    for (it = lst.begin(); it != lst.end(); it++) {
        // Thêm node vào vị trí thứ 1 (sau phần tử đầu tiên)
        if (i == 1) {
            lst.insert(it, 120);
        }
        i++;
    }

    i = 0;
    
    for(it = lst.begin(); it!=lst.end(); it++)
    {
        cout << "Node " << i++ << ", Value: " << *it << endl;
    }

    lst.pop_back();
lst.pop_back();
lst.pop_front();

cout << endl;

i = 0;
for (it = lst.begin(); it != lst.end(); it++)
{
    cout << "node: " << i++ << " - value: " << *it << endl;
}

i = 0;
for (it = lst.begin(); it != lst.end(); it++)
{
    // xóa node vị trí thứ 4
    if (i == 4)
    {
        lst.erase(it);
    }
    i++;
}



    return 0;
}

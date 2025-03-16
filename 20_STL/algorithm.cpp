#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    int count_even = 0;
    int count_odd = 0;
    vector<int> evens, odds;

    int result = count_if(vec.begin(), vec.end(), [&](int x)
    {
        if (x % 2 == 0)
        {
            count_even++;
            evens.push_back(x);
        }
        else if (x % 2 == 1)
        {
            count_odd++;
            odds.push_back(x);
        }
        return false;
    });

    cout << "Số lượng phần tử đã duyệt qua: " << result << endl;

    cout << "Number of even numbers: " << count_even << endl;
    for (auto item : evens)
    {
        cout << item << " ";
    }
    cout << endl;

    cout << "Number of odd numbers: " << count_odd << endl;
    for (auto item : odds)
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}

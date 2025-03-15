#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;

    cout << "Boot process" << endl;
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(4);

    vec.insert(vec.begin(), 40);
    vec.insert(vec.end(), 15);
    vec.insert(vec.end()-1, 10);

    for(auto item : vec)
    {
        cout << item << " ";
    }

    cout << "Pop process" << endl;
    vec.pop_back();
    vec.erase(vec.begin());
    vec.erase(vec.begin()+1);
    vec.erase(vec.end()-1);

    for(auto item : vec)
    {
        cout << item << " ";
    }

    cout << endl;
    return 0;
}

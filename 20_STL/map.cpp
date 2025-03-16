#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    map <int, string> arr; // key: int
                           // value: string

    arr[1] = "Cuong"; // cặp key value 1
    arr[2] = "CDT";   // cặp key value 2
    arr[10] = "21";   // cặp key value 3


    for(auto item : arr)
    {
        cout << "key: " << item.first << "value: " << item.second << endl;
    }

    map <int, string>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << "key: " << (*it).first << "value: " << (*it).second << endl;
    }

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Sensor
{
    private:
        T value;

    public:
        Sensor(T init): value(init){}

        T readSensor(T newValue);

        T getValue() const;

        void display()
        {
            cout << "Giá trị cảm biến: " << getValue() << endl;
        }
};

template <typename type>
type Sensor<type>::readSensor(type newValue)
{
    this->value = newValue;
}

template <typename T>
T Sensor<T>::getValue() const{ return value; }



template <typename T>
class Printer 
{
    public:
        void print(T value) 
        {
            cout << "Generic: " << value << endl;
        }
};

// Chuyên biệt hóa cho kiểu std::string
template <>
class Printer<string> 
{
    public:
        void print(string value) 
        {
            cout << "String specialization: " << value << endl;
        }
};


int main(int argc, char const *argv[])
{
    Sensor<int> tempSensor1(36.5);
    tempSensor1.display();

    Sensor tempSensor3(26.7);
    tempSensor3.display();

    Sensor<double> tempSensor2(25);
    tempSensor2.display();

    Sensor stateSensor("ON");
    stateSensor.display();

    return 0;
}

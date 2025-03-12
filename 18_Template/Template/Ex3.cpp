#include <iostream>
#include <string>

using namespace std;

class Sensor{
    public:
        virtual double getValue() const = 0;

        virtual string getUnit() const = 0;
};

// Class đại diện cho cảm biến nhiệt độ (Temperature Sensor)
class TemperatureSensor : public Sensor{
    private:
        double temp;

    public:
        double getValue() const override{
            // temp = 30.3;
            return 40.5; // Giá trị cảm biến giả định
        }

        string getUnit() const override{
            return "Celsius";
        }
};

// Class đại diện cho cảm biến áp suất lốp (Tire Pressure Sensor)
class TirePressureSensor : public Sensor{
    public:
        double getValue() const override {
            return 32; // Giá trị cảm biến giả định
        }

        string getUnit() const override {
            return "PSI";
        }
};

// Template class quản lý hai cảm biến khác nhau
template<typename Sensor1, typename Sensor2>
class VehicleSensors{
    private:
        Sensor1 sensor1;  // Đối tượng cảm biến 1
        Sensor2 sensor2;  // Đối tượng cảm biến 2

    public:
        // Constructor nhận vào hai đối tượng cảm biến
        VehicleSensors(Sensor1 s1, Sensor2 s2) : sensor1(s1), sensor2(s2) {}

        // Hàm hiển thị thông tin của cả hai cảm biến
        void displaySensorsInfo() const {
            cout << "Sensor 1 Value: " << sensor1.getValue() << " " << sensor1.getUnit() << endl;
            cout << "Sensor 2 Value: " << sensor2.getValue() << " " << sensor2.getUnit() << endl;
        }
};

int main()
{
    // Tạo đối tượng cảm biến nhiệt độ
    TemperatureSensor tempSensor;

    // Tạo đối tượng cảm biến áp suất lốp
    TirePressureSensor pressureSensor;

    // Quản lý cả hai cảm biến bằng class VehicleSensors
    VehicleSensors<TemperatureSensor, TirePressureSensor> vehicleSensors(tempSensor, pressureSensor);
    vehicleSensors.displaySensorsInfo();

    return 0;
}

#include <iostream>

using namespace std;

class Sensor
{
    public:
        // phương thức ảo thuần túy đọc dữ liệu cảm biến
        virtual void readData() = 0; 
};

class TemperatureSensor : public Sensor
{
    public:
        // Đọc dữ liệu cảm biến nhiệt độ
        void readData() override
        {
            cout << "reading temp Data..." << endl;
            // cấu hình, logic xử lý
        }
};

class HumiditySensor : public Sensor
{
    public:
        // Đọc dữ liệu cảm biến độ ẩm
        void readData() override
        {
            cout << "reading humidity Data..." << endl;
            // cấu hình, logic xử lý
        }
};

class PressureSensor : public Sensor
{
    public:
        // Đọc dữ liệu cảm biến áp suất
        void readData() override
        {
            cout << "reading pressure Data..." << endl;
            // cấu hình, logic xử lý
        }
};

// ứng dụng Factory pattern vào

typedef enum
{
    TEMP,
    PRES,
    HUMI
} SensorType;

class SensorFactory
{
    public:
        static Sensor* createSensor(SensorType type) // gọi thông qua static method
        {
            switch  (type)
            {
                case SensorType::TEMP:
                    return new TemperatureSensor();

                case SensorType::PRES:
                    return new PressureSensor();
                
                case SensorType::HUMI:
                    return new HumiditySensor();

                default:
                    cout<< "Không hợp lệ \n";
                    return nullptr;
            }
        }
};

int main(int argc, char const *argv[])
{
     Sensor* sensor1 = SensorFactory::createSensor(SensorType::TEMP); // tạo đối tượng cảm biến
     sensor1->readData();
    return 0;
}

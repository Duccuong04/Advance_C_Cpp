#include <iostream>

using namespace std;

class Sensor {
public:
    void initialize() {
        cout << "Initializing sensor" << endl;
        // code khởi tạo cảm biến
    }

    int readData() {
        cout << "Reading sensor data" << endl;
        // code đọc dữ liệu cảm biến
        return 30;
    }

    void test();
};

class Communication {
public:
    void setupCommunication() {
        cout << "Setting up communication protocol" << endl;
        // code thiết lập giao thức truyền thông (SPI, I2C, UART,...)
    }

    void sendData(int data) {
        cout << "Sending data: " << data << endl;
        // code gửi dữ liệu qua các giao thức
    }

    void test();
};

class Control : public Sensor, public Communication
{
public:
    Control() {
        setupCommunication();
        initialize();
        
        int data = readData();
        sendData(data);
    }
};

int main(int argc, char const *argv[])
{
    Control sensorControl;

    sensorControl.test();

    return 0;
}

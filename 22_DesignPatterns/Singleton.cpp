#include <iostream>

using namespace std;

void gpio_init()
{
    cout << "Configuration GPIO" << endl;
}

class GPIOManager
{
    // khai báo consructor là private để ngăn gọi đối tượng từ bên ngoài, chỉ gọi thông quá các method
    private:
        GPIOManager(){
            gpio_init();
        }

        static GPIOManager *instance;  // static có thể truy cập đượ tại bất cứ đâu

    public:
        static GPIOManager* createObj() // static method
        {
            if(instance == nullptr)
            {
                instance = new GPIOManager();
            }

            return instance;
        }
};

GPIOManager* GPIOManager::instance = nullptr;

int main(int argc, char const *argv[])
{
    GPIOManager::createObj(); // khởi tạo đối tượng 1 lần duy nhất thông qua static method
    return 0;
}

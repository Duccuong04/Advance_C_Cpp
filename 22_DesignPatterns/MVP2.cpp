#include <iostream>

using namespace std;

class ClimateControlModel{
    private:
        int temperature;    // Nhiệt độ hiện tại trong xe
        bool isAirOn;       // Trạng thái của điều hòa (bật/tắt)

    public:
        ClimateControlModel(int temp = 24, bool air = true): temperature(temp), isAirOn(air){}

        int getTemperature() const{
            return temperature;
        }

        bool getAirStatus() const{
            return isAirOn;
        }

        void setTemperature(int newTemperature){
            temperature = newTemperature;
        }

        void setAirStatus(bool status){
            isAirOn = status;
        }
};

class ClimateControlView{
    public:
        void displayCurrentSettings(int temperature, bool isAirOn){
            cout << "---- Thông tin điều hòa xe hơi ----" << endl;
            cout << "Nhiệt độ hiện tại: " << temperature << "°C" << endl;
            cout << "Trạng thái điều hòa: " << (isAirOn ? "Bật" : "Tắt") << endl;
        }

        int getUserTemperatureInput() {
            int temp;
            cout << "Nhập nhiệt độ mong muốn: ";
            cin >> temp;
            return temp;
        }

        bool getUserAirStatusInput() {
            int choice;
            cout << "Bật/Tắt điều hòa (1: Bật, 0: Tắt): ";
            cin >> choice;
            return (choice == 1);
        }
};

class ClimateControlPresenter{
    private:
        ClimateControlModel& model;
        ClimateControlView&  view;

    public:
        ClimateControlPresenter(ClimateControlModel& m, ClimateControlView& v): model(m), view(v){}

        void showCurrentSettings(){
            view.displayCurrentSettings(model.getTemperature(), model.getAirStatus());
        }

        void updateTemperature(){
            int newTemperature = view.getUserTemperatureInput();
            model.setTemperature(newTemperature);
        }

        void updateAirStatus(){
            bool newAirStatus = view.getUserAirStatusInput();
            model.setAirStatus(newAirStatus);
        }
};

int main()
{
    ClimateControlModel model;
    ClimateControlView view;
    ClimateControlPresenter presenter(model, view);

    int choice;
    do{
        cout << "\n1. Hiển thị thông tin điều hòa" << endl;
        cout << "2. Điều chỉnh nhiệt độ" << endl;
        cout << "3. Bật/Tắt điều hòa" << endl;
        cout << "4. Thoát" << endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;

        switch (choice){
            case 1:
                presenter.showCurrentSettings();
                break;

            case 2:
                presenter.updateTemperature();
                break;

            case 3:
                presenter.updateAirStatus();
                break;

            case 4:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }

    } while (choice != 4);

    return 0;
}



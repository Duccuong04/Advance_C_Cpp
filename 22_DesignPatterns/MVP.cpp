#include <iostream>
#include <string>

using namespace std;

/**
 * @class SinhVienModel
 * @brief Class lưu trữ thông tin của một sinh viên
 * @details Class này chứa các thuộc tính cơ bản của sinh viên, bao gồm tên, tuổi và mã số sinh viên
 *          Class này cung cấp các phương thức để truy cập và thay đổi thông tin sinh viên
 */

class SinhVienModel{
    private:
        string name;        /**< Tên của sinh viên  */
        int age;            /**< Tuổi của sinh viên */
        string studentId;   /**< Mã số sinh viên*/

    public:
        /**
         * @brief Cập nhật tên sinh viên
         * @param newName Tên mới của sinh viên
         */
        SinhVienModel(const string& name, int age, const string& studentId): name(name), age(age), studentId(studentId){}

        // setter method
        void setName(const string& newName){
            name = newName;
        }
         /**
         * @brief Cập nhật tuổi của sinh viên
         * @param newAge Tuổi mới của sinh viên
         */

        void setAge(int newAge){
            age = newAge;
        }

        void setStudentId(const string& newStudentId){
            studentId = newStudentId;
        }

        // getter method
        string getName() const{
            return name;
        }

        int getAge() const{
            return age;
        }

        string getStudentId() const{
            return studentId;
        }
};

/**
 * @class SinhVienView
 * @brief Class quản lý giao diện hiển thị và nhập liệu cho sinh viên
 * @details Class này chịu trách nhiệm hiển thị thông tin sinh viên ra màn hình
 *          và lấy thông tin sinh viên từ người dùng thông qua giao diện console
 */

class SinhVienView{
    public:
        void displayStudentInfo(const string& name, int age, const string& studentId){
            cout << "Thông tin sinh viên:" << endl;
            cout << "Tên: " << name << endl;
            cout << "Tuổi: " << age << endl;
            cout << "Mã số sinh viên: " << studentId << endl;
        }

        void inputStudentInfo(string& name, int& age, string& studentId){
            cout << "Nhập thông tin sinh viên:" << endl;

            cout << "Tên: ";
            getline(cin, name);

            cout << "Tuổi: ";
            cin >> age;
            cin.ignore();  // Bỏ qua ký tự newline trong buffer

            cout << "Mã số sinh viên: ";
            getline(cin, studentId);
        }
};

/**
 * @class SinhVienPresenter
 * @brief Class đóng vai trò trung gian giữa SinhVienModel & SinhVienView
 * @details Class này điều phối luồng dữ liệu giữa Model và View. Nó cập nhật dữ liệu từ người dùng vào
 *          thông qua View và hiển thị thông tin từ Model lên View
 */

class SinhVienPresenter{
    private:
        SinhVienModel& model;
        SinhVienView&  view;

    public:
        SinhVienPresenter(SinhVienModel& m, SinhVienView& v): model(m), view(v){}

        void updateStudentInfo(){
            string name;
            int age;
            string studentId;
           
            view.inputStudentInfo(name, age, studentId);
            model.setName(name);
            model.setAge(age);
            model.setStudentId(studentId);
        }

        void showStudentInfo(){
            view.displayStudentInfo(model.getName(), model.getAge(), model.getStudentId());
        }
};

int main()
{
    // Tạo model, view và presenter
    SinhVienModel model("Tuấn", 20, "HTN123");
    SinhVienView view;
    SinhVienPresenter presenter(model, view);

    int choice;
    do{
        cout << "\n1. Hiển thị thông tin sinh viên" << std::endl;
        cout << "2. Cập nhật thông tin sinh viên" << std::endl;
        cout << "3. Thoát" << std::endl;
        cout << "Nhập lựa chọn: ";
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự newline trong buffer
       
        switch (choice){
            case 1:
                presenter.showStudentInfo();
                break;
               
            case 2:
                presenter.updateStudentInfo();
                break;

            case 3:
                cout << "Thoát chương trình." << endl;
                break;

            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
        }
       
    } while (choice != 3);

    return 0;
}



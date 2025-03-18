/***********************************************************************************
 * @file    UniquePointer.hpp
 * @brief   Định nghĩa lớp UniquePointer để quản lý con trỏ động theo chuẩn RAII.
 * @details Lớp UniquePointer giúp quản lý bộ nhớ tự động và ngăn chặn các vấn đề
 *          liên quan đến bộ nhớ.
 * @version 1.0
 * @date    2025-12-03
 * @author  Anh Nguyen
 **********************************************************************************/

#ifndef UNIQUEPOINTER_HPP
#define UNIQUEPOINTER_HPP

/**
 * @class  UniquePointer
 * @brief  Mô phỏng 'std::unique_ptr', quản lý một con trỏ duy nhất và tự động giải phóng vùng nhớ..
 * @tparam T Kiểu dữ liệu của đối tượng được quản lý.
 */
template <typename T>
class UniquePointer
{
    private:
        T *ptr; /**< Con trỏ thô đến đối tượng được quản lý. */
        

    public:
        /**
         * @brief Constructor khởi tạo con trỏ UniquePointer.
         * @param[in]   p   Con trỏ thô đến đối tượng cần quản lý (mặc định là nullptr).
         */
        UniquePointer(T *p = nullptr) : ptr(p){}


        /**
         * @brief Destructor tự động giải phóng vùng nhớ của đối tượng khi đối tượng bị hủy.
         */
        ~UniquePointer()
        {
            if (ptr) delete ptr;
        }


        /**
         * @brief Copy Constructor - Xóa bỏ khả năng sao chép đối tượng UniquePointer.
         */
        UniquePointer(const UniquePointer &other) = delete;


        /**
         * @brief   Copy Assignment Operator - Xóa bỏ khả năng gán bằng copy đối tượng UniquePointer.
         * @return  Trả về tham chiếu đến đối tượng UniquePointer hiện tại.
         */
        UniquePointer& operator = (const UniquePointer &other) = delete;


        /**
         * @brief   Toán tử dereference để truy cập đối tượng được quản lý.
         * @return  Tham chiếu đến đối tượng được quản lý.
         */
        T& operator * () const
        {
            return *ptr;
        }


        /**
         * @brief   Toán tử arrow để truy cập các thành phần của đối tượng được quản lý.
         * @return  Con trỏ đến đối tượng được quản lý.
         */
        T* operator -> () const
        {
            return ptr;
        }


        /**
         * @brief   Trả về con trỏ thô đến đối tượng được quản lý.
         * @return  Con trỏ thô đến đối tượng.
         */        
        T* get() const
        {
            return ptr;
        }

        
        /**
         * @brief   Chuyển quyền sở hữu đối tượng cho con trỏ thô bên ngoài.
         * @return  Con trỏ thô đến đối tượng trước khi release.
         */
        T* release()
        {
            T* temp = ptr;  // lưu lại địa chỉ của đối tượng đang quản lý
            ptr = nullptr;  // đặt con trỏ thô ptr thành con trỏ null
            return temp;    // trả về địa chỉ của đối tượng
        }

        
        /**
         * @brief   Giải phóng đối tượng hiện tại và quản lý đối tượng mới.
         * @param[in]   newPtr   Con trỏ thô đến đối tượng mới (mặc định là nullptr).
         */
        void reset(T *newPtr = nullptr)
        {
            if (this->ptr) delete ptr;

            ptr = newPtr;
        }


        /**
         * @brief   Move constructor chuyển nhượng quyền sở hữu con trỏ.
         * @param[in]   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
         */
        UniquePointer(UniquePointer &&other) : ptr(other.ptr)
        {
            other.ptr = nullptr;
        }


        /**
         * @brief   Move Assignment Operator - Toán tử gán chuyển nhượng quyền sở hữu.
         * @param[in]   other   Đối tượng 'UniquePointer' cần chuyển nhượng quyền sở hữu.
         */
        UniquePointer& operator = (UniquePointer &&other)
        {
            if (this != &other)
            {
                // giải phóng đối tượng hiện tại
                if (this->ptr) delete ptr;

                // chuyển quyền sở hữu
                this->ptr = other.ptr;
                other.ptr = nullptr;
            }

            return *this;
        }
};

#endif  // UNIQUEPOINTER_HPP
#include <iostream>
#include <cstring>

class MyString 
{
    private:
        char* data;
        size_t length;

    public:
        // Constructors
        MyString() : data(nullptr), length(0) {}

        MyString(const char* str) 
        {
            length = std::strlen(str);
            data = new char[length + 1];
            std::strcpy(data, str);
        }

        MyString(const MyString& other) { // Copy constructor
            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
        }

        MyString(MyString&& other) noexcept // Move constructor
            : data(other.data), length(other.length) {
            other.data = nullptr;
            other.length = 0;
        }

        // Destructor
        ~MyString() {
            delete[] data;
        }

        // Assignment operator
        MyString& operator=(const MyString& other) {
            if (this == &other) return *this; // Self-assignment check
            delete[] data;

            length = other.length;
            data = new char[length + 1];
            std::strcpy(data, other.data);
            return *this;
        }

        MyString& operator=(MyString&& other) noexcept { // Move assignment
            if (this == &other) return *this; // Self-assignment check
            delete[] data;

            data = other.data;
            length = other.length;

            other.data = nullptr;
            other.length = 0;
            return *this;
        }

        // Overloading the + operator
        MyString operator+(const MyString& other) const {
            size_t newLength = length + other.length;
            char* newData = new char[newLength + 1];

            std::strcpy(newData, data);
            std::strcat(newData, other.data);

            MyString newString(newData);
            delete[] newData;
            return newString;
        }

        // Overloading the += operator
        MyString& operator+=(const MyString& other) {
            *this = *this + other;
            return *this;
        }

        // Overloading the [] operator
        char& operator[](size_t index) {
            return data[index];
        }

        const char& operator[](size_t index) const {
            return data[index];
        }

        // Overloading the == operator
        bool operator==(const MyString& other) const {
            return std::strcmp(data, other.data) == 0;
        }

        // Overloading the != operator
        bool operator!=(const MyString& other) const {
            return !(*this == other);
        }

        // Overloading the < operator
        bool operator<(const MyString& other) const {
            return std::strcmp(data, other.data) < 0;
        }

        // Overloading the <= operator
        bool operator<=(const MyString& other) const {
            return std::strcmp(data, other.data) <= 0;
        }

        // Overloading the > operator
        bool operator>(const MyString& other) const {
            return std::strcmp(data, other.data) > 0;
        }

        // Overloading the >= operator
        bool operator>=(const MyString& other) const {
            return std::strcmp(data, other.data) >= 0;
        }

        // Overloading the << operator for printing
        friend std::ostream& operator<<(std::ostream& os, const MyString& str) {
            os << str.data;
            return os;
        }

        // Length method
        size_t size() const {
            return length;
        }

        // Conversion operator to const char*
        operator const char*() const {
            return data;
        }
};

int main() {
    MyString str1 = "Hello";
    MyString str2 = " World";
    MyString str3 = str1 + str2;

    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;

    str1 += str2;
    std::cout << "After str1 += str2: " << str1 << std::endl;

    std::cout << "str3[0]: " << str3[0] << std::endl;
    std::cout << "Length of str3: " << str3.size() << std::endl;

    if (str1 == str3) {
        std::cout << "str1 is equal to str3" << std::endl;
    }

    return 0;
}

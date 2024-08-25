#include <iostream>

class MyInteger {
private:
    int value;

public:
    // Constructors
    MyInteger() : value(0) {}
    MyInteger(int val) : value(val) {}

    // Overloading the + operator
    MyInteger operator+(const MyInteger& other) const {
        return MyInteger(value + other.value);
    }

    // Overloading the - operator
    MyInteger operator-(const MyInteger& other) const {
        return MyInteger(value - other.value);
    }

    // Overloading the * operator
    MyInteger operator*(const MyInteger& other) const {
        return MyInteger(value * other.value);
    }

    // Overloading the / operator
    MyInteger operator/(const MyInteger& other) const {
        return MyInteger(value / other.value);
    }

    // Overloading the % operator
    MyInteger operator%(const MyInteger& other) const {
        return MyInteger(value % other.value);
    }

    // Overloading the == operator
    bool operator==(const MyInteger& other) const {
        return value == other.value;
    }

    // Overloading the != operator
    bool operator!=(const MyInteger& other) const {
        return value != other.value;
    }

    // Overloading the < operator
    bool operator<(const MyInteger& other) const {
        return value < other.value;
    }

    // Overloading the <= operator
    bool operator<=(const MyInteger& other) const {
        return value <= other.value;
    }

    // Overloading the > operator
    bool operator>(const MyInteger& other) const {
        return value > other.value;
    }

    // Overloading the >= operator
    bool operator>=(const MyInteger& other) const {
        return value >= other.value;
    }

    // Overloading the += operator
    MyInteger& operator+=(const MyInteger& other) {
        value += other.value;
        return *this;
    }

    // Overloading the -= operator
    MyInteger& operator-=(const MyInteger& other) {
        value -= other.value;
        return *this;
    }

    // Overloading the *= operator
    MyInteger& operator*=(const MyInteger& other) {
        value *= other.value;
        return *this;
    }

    // Overloading the /= operator
    MyInteger& operator/=(const MyInteger& other) {
        value /= other.value;
        return *this;
    }

    // Overloading the %= operator
    MyInteger& operator%=(const MyInteger& other) {
        value %= other.value;
        return *this;
    }

    // Overloading the << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const MyInteger& myInt) {
        os << myInt.value;
        return os;
    }

    // Conversion operator to int
    operator int() const {
        return value;
    }
};

int main() {
    MyInteger a = 5;
    MyInteger b = 10;

    MyInteger c = a + b;
    MyInteger d = b - a;

    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;

    c += b;
    std::cout << "After c += b: " << c << std::endl;

    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "b / a: " << b / a << std::endl;

    if (c > d) {
        std::cout << "c is greater than d" << std::endl;
    }

    return 0;
}

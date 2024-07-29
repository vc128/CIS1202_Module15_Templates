//Vivian Chang
//CIS 1202 Section 801
//07-29-24
#include <iostream>
#include <type_traits> // For type checking
using namespace std;

// Custom exception for invalid types
class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid data type!";
    }
};

// Function template to calculate half
template <typename T>
T half(T value) {
    if (!is_arithmetic_v<T>) {
        throw InvalidTypeException();
    }

    if constexpr (is_floating_point_v<T>) {
        return value / 2.0;
    }
    else if constexpr (is_integral_v<T>) {
        return round(value / 2.0);
    }
}

int main() {
    try {
        // Test cases
        cout << "Half of 7.0 (double): " << half(7.0) << endl; // Should be 3.75
        cout << "Half of 5.0 (float): " << half(5.0f) << endl; // Should be 2.5
        cout << "Half of 3 (int): " << half(3) << endl; // Should be 2
        
        cout << "Half of 'Hello' (string): " << half("Hello") << endl; // non-numeric type (e.g., string)
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

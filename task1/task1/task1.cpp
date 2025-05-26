#include <iostream>
using namespace std;

// Generic template function
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Specialization for type char*
template <>
void swapValues<char*>(char*& a, char*& b) {
    char* temp = a;
    a = b;
    b = temp;
}

int main() {
    // Test for type int
    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    // Test for type char*
    char str1[] = "Hello";
    char str2[] = "World";
    char* p1 = str1;
    char* p2 = str2;

    cout << "\nBefore swapping: p1 = " << p1 << ", p2 = " << p2 << endl;
    swapValues(p1, p2);
    cout << "After swapping: p1 = " << p1 << ", p2 = " << p2 << endl;

    return 0;
}

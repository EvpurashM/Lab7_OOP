#include <iostream>

// Array class
class Array {
private:
    int* data;
    int size;

public:
    Array(int sz) : size(sz) {
        data = new int[size];
        for (int i = 0; i < size; ++i)
            data[i] = i + 1; // Fill with test values
    }

    ~Array() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }

    // Nested Iterator class
    class Iterator {
    private:
        int* ptr;

    public:
        Iterator(int* p) : ptr(p) {}

        // Dereference operator
        int& operator*() const {
            return *ptr;
        }

        // Pre-increment operator
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Inequality comparison
        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }
    };

    // Begin and End functions
    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + size);
    }
};

// Main function for testing
int main() {
    Array arr(5);

    std::cout << "Array contents using iterator:\n";
    for (Array::Iterator it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

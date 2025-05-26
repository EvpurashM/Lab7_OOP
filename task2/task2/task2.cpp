#include <iostream>
#include <cstring> // for strcmp
using namespace std;

// Template function for insertion sort
template <typename T>
void insertionSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Specialization of the template for char*
template <>
void insertionSort<char*>(char* arr[], int n) {
    for (int i = 1; i < n; i++) {
        char* key = arr[i];
        int j = i - 1;

        // Compare strings using strcmp
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    // Test 1: int array
    int intArr[] = { 4, 2, 5, 1, 3 };
    int n = sizeof(intArr) / sizeof(intArr[0]);

    insertionSort(intArr, n);

    cout << "Sorted int array:\n";
    for (int i = 0; i < n; i++)
        cout << intArr[i] << " ";
    cout << "\n\n";

    // Test 2: char* array
    char str1[] = "banana";
    char str2[] = "apple";
    char str3[] = "grape";
    char str4[] = "cherry";

    // Array of pointers to C-strings
    char* strArr[] = { str1, str2, str3, str4 };
    int m = sizeof(strArr) / sizeof(strArr[0]);

    insertionSort(strArr, m);

    cout << "Sorted char* array:\n";
    for (int i = 0; i < m; i++)
        cout << strArr[i] << " ";
    cout << endl;

    return 0;
}

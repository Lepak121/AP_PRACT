#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sortDescendingRecursive(int array[], int start, int end) {
    if (start < end) {
        int maxIndex = start;
        for (int i = start + 1; i <= end; ++i) {
            if (array[i] > array[maxIndex]) {
                maxIndex = i;
            }
        }
        swap(array[start], array[maxIndex]);
        sortDescendingRecursive(array, start + 1, end);
    }
}

int main() {
    
    const int arraySize = 5;
    int myArray[arraySize] = { 3, 1, 4, 2, 5 };

    cout << "Masyv: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << myArray[i] << " ";
    }

    sortDescendingRecursive(myArray, 0, arraySize - 1);

    cout << "\nVidcortovanyi masyv: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }

    return 0;
}

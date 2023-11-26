#include <iostream>
using namespace std;
void sortDescending(int array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        for (int j = i + 1; j < arraySize; ++j) {
            if (array[i] < array[j]) {
               
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    
    const int arraySize = 5;
    int myArray[arraySize] = { 3, 1, 4, 2, 5 };

    cout << "Masyv: ";
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }

    sortDescending(myArray, arraySize);

    cout << "\nvidsortovaniy masyv ";
    for (int i = 0; i < arraySize; ++i) {
        cout << myArray[i] << " ";
    }

    return 0;
}

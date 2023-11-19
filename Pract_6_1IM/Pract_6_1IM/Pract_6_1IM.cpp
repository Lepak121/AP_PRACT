#include <time.h>
#include <iostream>
using namespace std;

int* applyCriteria(int* array, int size, int& sum, int& count) {
    for (int i = 0; i < size; i++) {
        if (array[i] > 0 && array[i] % 3 != 0) {
            count++;
            sum += array[i];
        }
        else {
            array[i] = 0;
        }
    }
    return array;
}

int main() {
    const int arraySize = 22;
    int sum = 0;
    int count = 0;
    int array[arraySize];

    srand((unsigned)time(NULL));

   
    for (int i = 0; i < arraySize; i++) {
        array[i] = -10 + rand() % (35 + 10 + 1);
        cout << array[i] << " ";
    }
    cout << "\n";

  
    applyCriteria(array, arraySize, sum, count);

    cout << "sum: " << sum << "\n";
    cout << "count: " << count << "\n";

  
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }

    return 0;
}

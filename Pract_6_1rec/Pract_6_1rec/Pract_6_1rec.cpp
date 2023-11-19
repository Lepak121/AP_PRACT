#include <time.h>
#include <iostream>
using namespace std;

void applyCriteria(int array[], int index, int arraySize, int& count, int& sum) {
    if (index < arraySize) {
        if (array[index] > 0 && array[index] % 3 != 0) {
            sum += array[index];
            count++;
            array[index] = 0;
        }
        applyCriteria(array, index + 1, arraySize, count, sum);
    }
}

void printArray(const int array[], int index, int arraySize) {
    if (index < arraySize) {
        cout << array[index] << " ";
        printArray(array, index + 1, arraySize);
    }
    else {
        cout << "\n";
    }
}

void initializeArray(int array[], int index, int arraySize) {
    if (index < arraySize) {
        array[index] = -10 + rand() % (35 + 10 + 1);
        initializeArray(array, index + 1, arraySize);
    }
}

int main()
{
    const int arraySize = 22;
    int sum = 0;
    int count = 0;
    int array[arraySize];
    srand((unsigned)time(NULL));

    initializeArray(array, 0, arraySize);
    printArray(array, 0, arraySize);

    applyCriteria(array, 0, arraySize, count, sum);

    cout << "sum: " << sum << "\n";
    cout << "count: " << count << "\n";

    printArray(array, 0, arraySize);

    return 0;
}

#include <iostream>
#include <windows.h>

int findMaxIndexRecursive(const int* array, int size, int currentIndex = 0, int maxIndex = 0) {
    if (currentIndex == size) {
        return maxIndex;
    }

    if (array[currentIndex] > array[maxIndex]) {
        maxIndex = currentIndex;
    }

    return findMaxIndexRecursive(array, size, currentIndex + 1, maxIndex);
}

int findProductBetweenZerosRecursive(const int* array, int size, int currentIndex = 0, int firstZeroIndex = -1, int secondZeroIndex = -1) {
    if (currentIndex == size) {
        if (firstZeroIndex != -1 && secondZeroIndex != -1 && firstZeroIndex < secondZeroIndex) {
            int product = 1;
            for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
                product *= array[i];
            }
            return product;
        }
        else {
            return 0;
        }
    }

    if (array[currentIndex] == 0) {
        if (firstZeroIndex == -1) {
            firstZeroIndex = currentIndex;
        }
        else {
            secondZeroIndex = currentIndex;
        }
    }

    return findProductBetweenZerosRecursive(array, size, currentIndex + 1, firstZeroIndex, secondZeroIndex);
}

void rearrangeArrayRecursive(int* array, int size, int currentIndex = 0) {
    if (currentIndex < size / 2) {
        if (currentIndex % 2 == 0) {
            int temp = array[currentIndex];
            array[currentIndex] = array[size / 2 + currentIndex];
            array[size / 2 + currentIndex] = temp;
        }

        rearrangeArrayRecursive(array, size, currentIndex + 1);
    }
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    std::cout << "Введіть розмір масиву: " << std::endl;
    std::cin >> n;

    int* array = new int[n];

    std::cout << "Введіть елементи масиву:\n" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int maxIndex = findMaxIndexRecursive(array, n);
    std::cout << "Номер максимального елементу: " << maxIndex << std::endl;

    int productBetweenZeros = findProductBetweenZerosRecursive(array, n);
    std::cout << "Добуток елементів між першим і другим нульовими елементами: " << productBetweenZeros << std::endl;

    rearrangeArrayRecursive(array, n);

    std::cout << "Відсортований масив:\n" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}

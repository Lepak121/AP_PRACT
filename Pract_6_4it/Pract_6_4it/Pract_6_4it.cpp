#include <iostream>
#include <Windows.h> 

int findMaxIndex(const int* array, int size) {
    if (size <= 0) {
        return -1; 
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }

    return maxIndex;
}


int findProductBetweenZeros(const int* array, int size) {
    int firstZeroIndex = -1;
    int secondZeroIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (array[i] == 0) {
            if (firstZeroIndex == -1) {
                firstZeroIndex = i;
            }
            else {
                secondZeroIndex = i;
                break;
            }
        }
    }

    if (firstZeroIndex == -1 || secondZeroIndex == -1 || firstZeroIndex == secondZeroIndex) {
        return 0; 
    }

    int product = 1;
    for (int i = firstZeroIndex + 1; i < secondZeroIndex; ++i) {
        product *= array[i];
    }

    return product;
}


void rearrangeArray(int* array, int size) {
    for (int i = 0; i < size / 2; ++i) {
        if (i % 2 == 0) {
        
            int temp = array[i];
            array[i] = array[size / 2 + i];
            array[size / 2 + i] = temp;
        }
    }
}

int main() {
  
    SetConsoleOutputCP(1251);


    int n;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> n;

 
    int* array = new int[n];

 
    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

 
    int maxIndex = findMaxIndex(array, n);
    if (maxIndex != -1) {
        std::cout << "Номер максимального елементу: " << maxIndex << std::endl;
    }
    else {
        std::cout << "Масив порожній." << std::endl;
    }


    int productBetweenZeros = findProductBetweenZeros(array, n);
    if (productBetweenZeros != 0) {
        std::cout << "Добуток елементів між першим і другим нульовими елементами: " << productBetweenZeros << std::endl;
    }
    else {
        std::cout << "Неможливо знайти добуток (недостатньо нульових елементів або вони розташовані поруч)." << std::endl;
    }

 
    rearrangeArray(array, n);

    
    std::cout << "Відсортований масив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    delete[] array;

    return 0;
}

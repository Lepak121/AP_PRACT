#include <iostream>
#include <vector>
using namespace std;
int findIndexOfMinOddRecursive(const std::vector<int>& array, int currentIndex, int minOddIndex) {
    if (currentIndex < array.size()) {
        if (array[currentIndex] % 2 != 0 && (minOddIndex == -1 || array[currentIndex] < array[minOddIndex])) {
            return findIndexOfMinOddRecursive(array, currentIndex + 1, currentIndex);
        }
        else {
            return findIndexOfMinOddRecursive(array, currentIndex + 1, minOddIndex);
        }
    }
    else {
        return minOddIndex;
    }
}

int main() {

    vector<int> myVector = { 2, 7, 1, 9, 4, 6, 5 };

    int resultIndex = findIndexOfMinOddRecursive(myVector, 0, -1);

    if (resultIndex != -1) {
       cout << "Index naimeshogo: " << resultIndex << endl;
    }
    else {
        cout << "U vektori nema nep znach" << endl;
    }

    return 0;
}

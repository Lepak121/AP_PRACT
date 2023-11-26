#include <iostream>
#include <vector>
using namespace  std;
int findIndexOfMinOdd(const vector<int>& array) {
    int minOddIndex = -1;
    int minOddValue = INT_MAX;

    for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 != 0 && array[i] < minOddValue) {
            minOddValue = array[i];
            minOddIndex = i;
        }
    }

    return minOddIndex;
}

int main() {

    vector<int> myVector = { 2, 7, 1, 9, 4, 6, 5 };

    int resultIndex = findIndexOfMinOdd(myVector);

    if (resultIndex != -1) {
        cout << "index naimenshogo elementa " << resultIndex << endl;
    }
    else {
        cout << "U vektori nemaye neparnux chusel" << endl;
    }

    return 0;
}

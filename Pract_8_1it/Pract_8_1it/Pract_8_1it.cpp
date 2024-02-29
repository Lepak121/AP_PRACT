#include <iostream>
#include <cstring> 

using namespace std;

int CountQuadruplets(char* str) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len - 3; i++) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            count++;
        }
    }
    return count;
}

char* ReplaceQuadruplets(char* str) {
    int len = strlen(str);
    char* result = new char[len * 2 + 1]; 
    int index = 0; 
    for (int i = 0; i < len; i++) {
        if (i <= len - 4 && str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            result[index++] = '*';
            result[index++] = '*'; 
            i += 3; 
        }
        else {
            result[index++] = str[i];
        }
    }
    result[index] = '\0'; 
    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

 
    int count = CountQuadruplets(str);
    cout << "Number of quadruplets found: " << count << endl;

   
    char* modifiedStr = ReplaceQuadruplets(str);
    cout << "Modified string: " << modifiedStr << endl;


    return 0;
}

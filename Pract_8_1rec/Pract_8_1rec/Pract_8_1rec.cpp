#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int Count(const std::string& str, int i) {
    if (str.length() < 4)
        return 0;

    if (i + 3 < str.length()) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3])
            return 1 + Count(str, i + 1);
        else
            return Count(str, i + 1);
    }
    else
        return 0;
}

std::string Change(const std::string& str, int i) {
    std::string result;

    if (i + 3 < str.length()) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2] && str[i] == str[i + 3]) {
            result += "**";
            return result + Change(str, i + 4);
        }
        else {
            result += str[i++];
            return result + Change(str, i);
        }
    }
    else {
        while (i < str.length()) {
            result += str[i++];
        }
        return result;
    }
}

int main() {
    std::string str;
    std::cout << "Enter string:" << std::endl;
    std::getline(std::cin, str);

    int count = Count(str, 0);
    std::cout << "Number of quadruplets found: " << count << std::endl;

    std::string modifiedStr = Change(str, 0);
    std::cout << "Modified string (result): " << modifiedStr << std::endl;

    return 0;
}

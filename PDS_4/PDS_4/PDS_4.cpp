#include <iostream>
#include <algorithm>
#include <vector>
#include <Windows.h>

void printVector(const std::vector<int>& vec) {
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


void generatePermutations(int n) {
    std::vector<int> permutation;
    for (int i = 1; i <= n; ++i) {
        permutation.push_back(i);
    }

    std::cout << "������������ ������� {1, 2, ..., " << n << "}:\n";
    do {
        printVector(permutation);
    } while (std::next_permutation(permutation.begin(), permutation.end()));
}


void generateCombinations(const std::vector<int>& elements, std::vector<int>& combination, int start, int r) {
    if (r == 0) {
        printVector(combination);
        return;
    }

    for (int i = start; i <= elements.size() - r; ++i) {
        combination.push_back(elements[i]);
        generateCombinations(elements, combination, i + 1, r - 1);
        combination.pop_back();
    }
}


void generateRCombinations(int n, int r) {
    if (r > n || r < 0) {
        std::cerr << "���������� �������� r. �������������, �� 0 <= r <= n." << std::endl;
        return;
    }

    std::vector<int> elements;
    for (int i = 1; i <= n; ++i) {
        elements.push_back(i);
    }

    std::vector<int> combination;
    std::cout << "r-���������� ��� ��������� � �������� ������� {1, 2, ..., " << n << "}:\n";
    generateCombinations(elements, combination, 0, r);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, r;
    std::cout << "�������� 1: ������������\n";
    std::cout << "������ ���������� ����� n: ";
    std::cin >> n;
    generatePermutations(n);


    std::cout << "\n�������� 2: r-����������\n";
    std::cout << "������ ���������� ����� n: ";
    std::cin >> n;
    std::cout << "������ ����'���� ���� ����� r (r <= n): ";
    std::cin >> r;
    generateRCombinations(n, r);

    return 0;
}
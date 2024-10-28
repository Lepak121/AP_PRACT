#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;


void readGraph(const string& filename, int& n, int& m, vector<pair<int, int>>& edges) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ����: " << filename << endl;
        exit(1);
    }

    file >> n >> m;
    edges.resize(m);

    for (int i = 0; i < m; ++i) {
        int vi, ui;
        file >> vi >> ui;
        edges[i] = { vi, ui };
    }

    file.close();
}


vector<vector<int>> createIncidenceMatrix(int n, int m, const vector<pair<int, int>>& edges) {
    vector<vector<int>> incidenceMatrix(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i) {
        int vi = edges[i].first - 1;
        int ui = edges[i].second - 1;
        incidenceMatrix[vi][i] = 1;
        incidenceMatrix[ui][i] = -1;
    }

    return incidenceMatrix;
}


vector<vector<int>> createAdjacencyMatrix(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    for (const auto& edge : edges) {
        int vi = edge.first - 1;
        int ui = edge.second - 1;
        adjacencyMatrix[vi][ui] = 1;
    }

    return adjacencyMatrix;
}


void printMatrix(const vector<vector<int>>& matrix, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "�� ������� ������� ���� ��� ������: " << filename << endl;
        return;
    }

    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
            file << value << " ";
        }
        cout << endl;
        file << endl;
    }

    file.close();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);  
    int n, m;
    vector<pair<int, int>> edges;
    string inputFilename, outputFilename;

    cout << "�������� 1: ���������� ����� � �������� �����" << endl;
    cout << "������ ����� �������� �����: ";
    cin >> inputFilename;

    readGraph(inputFilename, n, m, edges);

    cout << "���� ������ ��������!" << endl;


    auto incidenceMatrix = createIncidenceMatrix(n, m, edges);
    auto adjacencyMatrix = createAdjacencyMatrix(n, edges);

    cout << "�������� 2: ���� ������� ������������ �� ��������" << endl;
    cout << "������ ����� ��������� ����� ��� ���������� �������: ";
    cin >> outputFilename;

    cout << "������ ������� ��� ������ (1 - ������������, 2 - ��������): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "������� ������������:" << endl;
        printMatrix(incidenceMatrix, outputFilename);
    }
    else if (choice == 2) {
        cout << "������� ��������:" << endl;
        printMatrix(adjacencyMatrix, outputFilename);
    }
    else {
        cout << "������������ ����!" << endl;
    }

    return 0;
}
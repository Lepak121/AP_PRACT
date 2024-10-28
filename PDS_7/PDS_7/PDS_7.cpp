#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;


vector<vector<int>> readGraph(const string& filename) {
    ifstream file(filename);
    vector<vector<int>> graph;


    if (!file.is_open()) {
        cerr << "�������: �� ������� ������� ���� " << filename << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<int> row;
        int value;
        while (ss >> value) {
            row.push_back(value);
        }

        if (!graph.empty() && row.size() != graph[0].size()) {
            cerr << "�������: ����������� ������ �����. ʳ������ �������� � ������ �� �������." << endl;
            exit(EXIT_FAILURE);
        }
        graph.push_back(row);
    }

    file.close();
    return graph;
}


void calculateDegrees(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "�������: ���� �������." << endl;
        return;
    }

    vector<int> inDegree(vertices, 0);
    vector<int> outDegree(vertices, 0);

    for (int i = 0; i < vertices; ++i) {
        if (graph[i].size() != vertices) {
            cerr << "�������: ����������� ����� ������� ��������." << endl;
            return;
        }

        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    cout << "������ ������ ����� (������/������):\n";
    for (int i = 0; i < vertices; ++i) {
        cout << "������� " << i + 1 << ": �������� ������ = " << outDegree[i]
            << ", ������� ������ = " << inDegree[i] << endl;
    }


    bool isHomogeneous = true;
    int degree = outDegree[0];
    for (int i = 1; i < vertices; ++i) {
        if (outDegree[i] != degree || inDegree[i] != degree) {
            isHomogeneous = false;
            break;
        }
    }

    if (isHomogeneous) {
        cout << "���� � ��������� � �������� ����������: " << degree << endl;
    }
    else {
        cout << "���� �� � ���������." << endl;
    }
}


void findPendantAndIsolatedVertices(const vector<vector<int>>& graph) {
    int vertices = graph.size();
    if (vertices == 0) {
        cerr << "�������: ���� �������." << endl;
        return;
    }

    vector<int> degree(vertices, 0);
    vector<int> pendantVertices;
    vector<int> isolatedVertices;

    for (int i = 0; i < vertices; ++i) {
        if (graph[i].size() != vertices) {
            cerr << "�������: ����������� ����� ������� ��������." << endl;
            return;
        }

        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] != 0) {
                degree[i]++;
            }
        }
        if (degree[i] == 1) {
            pendantVertices.push_back(i + 1);
        }
        else if (degree[i] == 0) {
            isolatedVertices.push_back(i + 1);
        }
    }

    cout << "������ �������: ";
    if (pendantVertices.empty()) {
        cout << "����\n";
    }
    else {
        for (int vertex : pendantVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    cout << "��������� �������: ";
    if (isolatedVertices.empty()) {
        cout << "����\n";
    }
    else {
        for (int vertex : isolatedVertices) {
            cout << vertex << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string filename;
    cout << "������ ����� �������� ����� � ������ �����: ";
    cin >> filename;

    vector<vector<int>> graph = readGraph(filename);

    cout << "\n�������� 1: ���������� ������� ������ �����.\n";
    calculateDegrees(graph);

    cout << "\n�������� 2: ���������� ������� �� ����������� ������ �����.\n";
    findPendantAndIsolatedVertices(graph);

    return 0;
}
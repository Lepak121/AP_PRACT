#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

enum Specialty {
    COMPUTER_SCIENCE,
    INFORMATICS,
    MATH_ECONOMICS,
    PHYSICS_INFORMATICS,
    LABOUR_TRAINING
};

union AdditionalGrade {
    int programming;
    int numericalMethods;
    int pedagogy;
};

struct Student {
    string lastName;
    int course;
    Specialty specialty;
    int physicsGrade;
    int mathGrade;
    AdditionalGrade additionalGrade;
};

vector<Student> readDataFromFile(const string& filename) {
    ifstream file(filename);
    vector<Student> studentsData;
    string line;
    while (getline(file, line)) {
        Student student;
        stringstream ss(line);
        ss >> student.lastName >> student.course;
        string specialtyStr;
        ss >> specialtyStr;
        if (specialtyStr == "COMPUTER_SCIENCE") {
            student.specialty = COMPUTER_SCIENCE;
        }
        else if (specialtyStr == "INFORMATICS") {
            student.specialty = INFORMATICS;
        }
        else if (specialtyStr == "MATH_ECONOMICS") {
            student.specialty = MATH_ECONOMICS;
        }
        else if (specialtyStr == "PHYSICS_INFORMATICS") {
            student.specialty = PHYSICS_INFORMATICS;
        }
        else if (specialtyStr == "LABOUR_TRAINING") {
            student.specialty = LABOUR_TRAINING;
        }
        ss >> student.physicsGrade >> student.mathGrade >> student.additionalGrade.programming;
        studentsData.push_back(student);
    }
    file.close();
    return studentsData;
}

void printHeader() {
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "| No. | Last Name | Course | Specialty | Physics | Math | Additional Grade (Programming/Numerical Methods/Pedagogy) |\n";
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void printStudent(int index, const Student& student) {
    cout << "| " << index + 1 << ". ";
    cout.width(10);
    cout << student.lastName << " | ";
    cout << student.course << " | ";
    switch (student.specialty) {
    case COMPUTER_SCIENCE:
        cout << "Computer Science";
        break;
    case INFORMATICS:
        cout << "Informatics";
        break;
    case MATH_ECONOMICS:
        cout << "Mathematics and Economics";
        break;
    case PHYSICS_INFORMATICS:
        cout << "Physics and Informatics";
        break;
    case LABOUR_TRAINING:
        cout << "Labour Training";
        break;
    }
    cout << " | ";
    cout << student.physicsGrade << " | ";
    cout << student.mathGrade << " | ";
    cout << student.additionalGrade.programming << " |\n";
}

void printStudents(const vector<Student>& studentsData) {
    printHeader();
    for (int i = 0; i < studentsData.size(); ++i) {
        printStudent(i, studentsData[i]);
    }
}

int countExcellentGrades(const vector<Student>& studentsData, int grade) {
    int excellentCount = 0;
    for (const auto& student : studentsData) {
        if (student.physicsGrade == grade || student.mathGrade == grade) {
            excellentCount++;
        }
    }
    return excellentCount;
}

int countStudentsWithGrades(const vector<Student>& studentsData, int physicsGrade, int mathGrade) {
    int countStudents = 0;
    for (const auto& student : studentsData) {
        if (student.physicsGrade == physicsGrade && student.mathGrade == mathGrade) {
            countStudents++;
        }
    }
    return countStudents;
}

int main() {
    string filepath;
    cout << "Enter the path to the file: ";
    getline(cin, filepath);

    vector<Student> studentsData = readDataFromFile(filepath);

    printStudents(studentsData);

    int excellentCountPhysics = countExcellentGrades(studentsData, 5);
    int excellentCountMath = countExcellentGrades(studentsData, 5);
    cout << "Number of 'excellent' grades in Physics: " << excellentCountPhysics << endl;
    cout << "Number of 'excellent' grades in Mathematics: " << excellentCountMath << endl;

    int countStudentsWithTopGrades = countStudentsWithGrades(studentsData, 5, 5);
    cout << "Number of students who scored '5' in both Physics and Mathematics: " << countStudentsWithTopGrades << endl;

    return 0;
}

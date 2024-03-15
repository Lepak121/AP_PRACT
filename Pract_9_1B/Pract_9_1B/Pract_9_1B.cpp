#include <iostream>
#include <string>
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
    AdditionalGrade additionalGrade; // Використання об'єднання для третьої оцінки
};

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
    switch (student.specialty) {
    case COMPUTER_SCIENCE:
        cout << student.additionalGrade.programming << " |\n";
        break;
    case INFORMATICS:
        cout << student.additionalGrade.numericalMethods << " |\n";
        break;
    default:
        cout << student.additionalGrade.pedagogy << " |\n";
        break;
    }
}

void printStudents(const Student* students, int count) {
    printHeader();
    for (int i = 0; i < count; ++i) {
        printStudent(i, students[i]);
    }
}

int countExcellentGrades(const Student* students, int count, int grade) {
    int excellentCount = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i].physicsGrade == grade || students[i].mathGrade == grade) {
            excellentCount++;
        }
    }
    return excellentCount;
}

int countStudentsWithGrades(const Student* students, int count, int physicsGrade, int mathGrade) {
    int countStudents = 0;
    for (int i = 0; i < count; ++i) {
        if (students[i].physicsGrade == physicsGrade && students[i].mathGrade == mathGrade) {
            countStudents++;
        }
    }
    return countStudents;
}

int main() {
    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;

    Student* students = new Student[studentCount];

    for (int i = 0; i < studentCount; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Course: ";
        cin >> students[i].course;
        cout << "Specialty (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Labour Training): ";
        int specialty;
        cin >> specialty;
        students[i].specialty = static_cast<Specialty>(specialty);
        cout << "Physics Grade: ";
        cin >> students[i].physicsGrade;
        cout << "Math Grade: ";
        cin >> students[i].mathGrade;

        switch (students[i].specialty) {
        case COMPUTER_SCIENCE:
            cout << "Programming Grade: ";
            cin >> students[i].additionalGrade.programming;
            break;
        case INFORMATICS:
            cout << "Numerical Methods Grade: ";
            cin >> students[i].additionalGrade.numericalMethods;
            break;
        default:
            cout << "Pedagogy Grade: ";
            cin >> students[i].additionalGrade.pedagogy;
            break;
        }
    }

    printStudents(students, studentCount);

    int excellentCountPhysics = countExcellentGrades(students, studentCount, 5);
    int excellentCountMath = countExcellentGrades(students, studentCount, 5);
    cout << "Number of 'Excellent' grades in Physics: " << excellentCountPhysics << endl;
    cout << "Number of 'Excellent' grades in Math: " << excellentCountMath << endl;


    int countStudentsWithTopGrades = countStudentsWithGrades(students, studentCount, 5, 5);
    cout << "Number of students who received '5' in Physics and Math: " << countStudentsWithTopGrades << endl;

    delete[] students;

    return 0;
}

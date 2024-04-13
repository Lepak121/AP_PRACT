#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

union Marks {
    int programming;
    int numericalMethods;
    int pedagogy;
};

struct Student {
    string lastName;
    int course;
    string specialty;
    int physicsGrade;
    int mathGrade;
    Marks marks;
    double averageGrade;
};

void enterStudentData(Student& student) {
    cout << "Enter last name: ";
    cin >> student.lastName;
    cout << "Enter course: ";
    cin >> student.course;


    cout << "Select specialty:" << endl;
    cout << "1. Computer Science" << endl;
    cout << "2. Informatics" << endl;
    cout << "3. Other" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        student.specialty = "Computer Science";
        cout << "Enter programming grade: ";
        cin >> student.marks.programming;
        break;
    case 2:
        student.specialty = "Informatics";
        cout << "Enter numerical methods grade: ";
        cin >> student.marks.numericalMethods;
        break;
    case 3:
        cout << "Enter specialty: ";
        cin >> student.specialty;
        cout << "Enter pedagogy grade: ";
        cin >> student.marks.pedagogy;
        break;
    default:
        cout << "Invalid choice. Using default specialty: Computer Science" << endl;
        student.specialty = "Computer Science";
        cout << "Enter programming grade: ";
        cin >> student.marks.programming;
    }


    cout << "Enter physics grade: ";
    cin >> student.physicsGrade;
    cout << "Enter math grade: ";
    cin >> student.mathGrade;


    if (student.specialty == "Computer Science") {
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.marks.programming) / 3.0;
    }
    else if (student.specialty == "Informatics") {
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.marks.numericalMethods) / 3.0;
    }
    else {
        student.averageGrade = (student.physicsGrade + student.mathGrade + student.marks.pedagogy) / 3.0;
    }
}


void printTableHeader() {
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "| No. | Last Name | Course | Specialty | Physics | Math | Other Grade      | Average Grade |" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}

void printStudentData(const Student& student, int index) {
    cout << "| " << index + 1 << "   | " << student.lastName << " | " << student.course << "      | " << student.specialty << "    | " << student.physicsGrade << "     | " << student.mathGrade << "   | ";
    if (student.specialty == "Computer Science") {
        cout << student.marks.programming << "            ";
    }
    else if (student.specialty == "Informatics") {
        cout << student.marks.numericalMethods << "               ";
    }
    else {
        cout << student.marks.pedagogy << "                   ";
    }
    cout << "| " << student.averageGrade << "         |" << endl;
}

void enterStudentsData(Student* students, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        enterStudentData(students[i]);
    }
}

void printStudentsData(const Student* students, int count) {
    printTableHeader();
    for (int i = 0; i < count; ++i) {
        printStudentData(students[i], i);
    }
    cout << "---------------------------------------------------------------------------" << endl;
}

bool compareStudents(const Student& a, const Student& b) {
    if (a.averageGrade != b.averageGrade)
        return a.averageGrade > b.averageGrade; 
    if (a.specialty != b.specialty)
        return a.specialty < b.specialty; 
    return a.lastName < b.lastName; 
}


void sortStudentsByAverageGrade(Student* students, int count) {
    sort(students, students + count, compareStudents);
}

void buildIndexArray(const Student* students, int count, int* indexArray) {
    for (int i = 0; i < count; ++i) {
        indexArray[i] = i;
    }
    sort(indexArray, indexArray + count, [&students](int a, int b) {
        if (students[a].averageGrade != students[b].averageGrade)
            return students[a].averageGrade > students[b].averageGrade;
        if (students[a].specialty != students[b].specialty)
            return students[a].specialty < students[b].specialty;
        return students[a].lastName < students[b].lastName;
        });
}

bool binarySearch(const Student* students, int count, const string& lastName, const string& specialty, double targetGrade) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].lastName == lastName && students[mid].specialty == specialty && students[mid].averageGrade == targetGrade) {
            return true;
        }
        else if (students[mid].averageGrade > targetGrade ||
            (students[mid].averageGrade == targetGrade && students[mid].specialty > specialty) ||
            (students[mid].averageGrade == targetGrade && students[mid].specialty == specialty && students[mid].lastName > lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;

    Student* students = new Student[studentCount];

    enterStudentsData(students, studentCount);

    sortStudentsByAverageGrade(students, studentCount);

    cout << endl << "Students data sorted by average grade:" << endl;
    printStudentsData(students, studentCount);

    int* indexArray = new int[studentCount];
    buildIndexArray(students, studentCount, indexArray);

    string searchLastName;
    string searchSpecialty;
    double searchGrade;
    cout << "Enter last name to search: ";
    cin >> searchLastName;
    cout << "Enter specialty to search: ";
    cin >> searchSpecialty;
    cout << "Enter target average grade to search: ";
    cin >> searchGrade;
    if (binarySearch(students, studentCount, searchLastName, searchSpecialty, searchGrade)) {
        cout << "Student with last name '" << searchLastName << "', specialty '" << searchSpecialty << "', and average grade '" << searchGrade << "' found." << endl;
    }
    else {
        cout << "Student not found." << endl;
    }

    delete[] students;
    delete[] indexArray;

    return 0;
}

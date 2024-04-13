#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

void enterStudentsData(vector<Student>& students, int count) {
    for (int i = 0; i < count; ++i) {
        cout << "Enter data for student " << i + 1 << ":" << endl;
        Student student;
        enterStudentData(student);
        students.push_back(student);
    }
}

void printStudentsData(const vector<Student>& students) {
    printTableHeader();
    for (size_t i = 0; i < students.size(); ++i) {
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

void sortStudentsByAverageGrade(vector<Student>& students) {
    sort(students.begin(), students.end(), compareStudents);
}

void buildIndexArray(const vector<Student>& students, vector<int>& indexArray) {
    indexArray.resize(students.size());
    for (size_t i = 0; i < students.size(); ++i) {
        indexArray[i] = i;
    }
    sort(indexArray.begin(), indexArray.end(), [&students](int a, int b) {
        if (students[a].averageGrade != students[b].averageGrade)
            return students[a].averageGrade > students[b].averageGrade;
        if (students[a].specialty != students[b].specialty)
            return students[a].specialty < students[b].specialty;
        return students[a].lastName < students[b].lastName;
        });
}

bool binarySearch(const vector<Student>& students, const string& lastName, const string& specialty, double targetGrade) {
    int left = 0;
    int right = students.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].lastName == lastName && students[mid].specialty == specialty && students[mid].averageGrade == targetGrade) {
            return true;
        }
        else if (students[mid].averageGrade > targetGrade ||
            (students[mid].averageGrade == targetGrade && students[mid].specialty > specialty) ||
            (students[mid].averageGrade == targetGrade && students[mid].specialty ==
                specialty && students[mid].lastName > lastName)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<Student> students;
    int studentCount;
    cout << "Enter the number of students: ";
    cin >> studentCount;
    enterStudentsData(students, studentCount);

    sortStudentsByAverageGrade(students);

    cout << endl << "Students data sorted by average grade:" << endl;
    printStudentsData(students);

    vector<int> indexArray;
    buildIndexArray(students, indexArray);

    string searchLastName;
    string searchSpecialty;
    double searchGrade;
    cout << "Enter last name to search: ";
    cin >> searchLastName;
    cout << "Enter specialty to search: ";
    cin >> searchSpecialty;
    cout << "Enter target average grade to search: ";
    cin >> searchGrade;
    if (binarySearch(students, searchLastName, searchSpecialty, searchGrade)) {
        cout << "Student with last name '" << searchLastName << "', specialty '" << searchSpecialty
            << "', and average grade '" << searchGrade << "' found." << endl;
    }
    else {
        cout << "Student not found." << endl;
    }

    // Writing data to a file
    string filename;
    cout << "Enter filename to save data: ";
    cin >> filename;

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    // Writing table header
    outFile << "No. | Last Name | Course | Specialty | Physics | Math | Other Grade | Average Grade" << endl;

    // Writing student data
    for (size_t i = 0; i < students.size(); ++i) {
        outFile << i + 1 << " | " << students[i].lastName << " | " << students[i].course << " | " << students[i].specialty << " | "
            << students[i].physicsGrade << " | " << students[i].mathGrade << " | ";
        if (students[i].specialty == "Computer Science") {
            outFile << students[i].marks.programming;
        }
        else if (students[i].specialty == "Informatics") {
            outFile << students[i].marks.numericalMethods;
        }
        else {
            outFile << students[i].marks.pedagogy;
        }
        outFile << " | " << students[i].averageGrade << endl;
    }

    cout << "Data saved to file '" << filename << "'." << endl;

    outFile.close();

    return 0;
}

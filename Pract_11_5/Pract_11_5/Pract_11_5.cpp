#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Student {
    int course;
    string group;
    string surname;
    double averageGrade;
};

struct Institute {
    string name;
    vector<Student> students;
};

void writeArrayToFile(const string& filename, const vector<Institute>& institutes) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    for (const auto& institute : institutes) {
        file.write(reinterpret_cast<const char*>(&institute), sizeof(Institute));
    }

    file.close();
}

void readArrayFromFile(const string& filename, vector<Institute>& institutes) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    Institute institute;
    while (file.read(reinterpret_cast<char*>(&institute), sizeof(Institute))) {
        institutes.push_back(institute);
    }

    file.close();
}

void addDataToFile(const string& filename, const Institute& institute) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&institute), sizeof(Institute));

    file.close();
}

void replaceDataInFile(const string& filename, const Institute& institute, int index) {
    fstream file(filename, ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    file.seekp(index * sizeof(Institute), ios::beg);
    file.write(reinterpret_cast<const char*>(&institute), sizeof(Institute));

    file.close();
}

void deleteDataFromFile(const string& filename, int index) {
    vector<Institute> institutes;
    readArrayFromFile(filename, institutes);

    if (index >= 0 && index < institutes.size()) {
        institutes.erase(institutes.begin() + index);
        writeArrayToFile(filename, institutes);
    }
    else {
        cout << "Invalid index!" << endl;
    }
}

void displayStudentsByCourseAndGroup(const vector<Institute>& institutes, int course, const string& group) {
    for (const auto& institute : institutes) {
        for (const auto& student : institute.students) {
            if (student.course == course && student.group == group) {
                cout << "Surname: " << student.surname << ", Average Grade: " << student.averageGrade << endl;
            }
        }
    }
}

void findBestFacultyAndGroup(const vector<Institute>& institutes) {
    string bestFaculty;
    string bestGroup;
    int maxExcellentStudents = 0;

    for (const auto& institute : institutes) {
        int excellentStudents = 0;
        for (const auto& student : institute.students) {
            if (student.averageGrade >= 4.5) {
                excellentStudents++;
            }
        }

        if (excellentStudents > maxExcellentStudents) {
            maxExcellentStudents = excellentStudents;
            bestFaculty = institute.name;
            bestGroup = institute.students[0].group;
        }
    }

    cout << "Faculty with the most excellent students: " << bestFaculty << ", Group: " << bestGroup << endl;
}

void addStudentToInstitute(Institute& institute) {
    Student student;
    cout << "Enter student's course: ";
    cin >> student.course;
    cout << "Enter student's group: ";
    cin >> student.group;
    cout << "Enter student's surname: ";
    cin >> student.surname;
    cout << "Enter student's average grade: ";
    cin >> student.averageGrade;

    institute.students.push_back(student);
}

int main() {
    vector<Institute> institutes;
    string filename;

    cout << "Enter the file name: ";
    cin >> filename;

    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1; // Повертаємо 1, щоб позначити помилку
    }

    // Читаємо дані з файлу
    Institute institute;
    while (file.read(reinterpret_cast<char*>(&institute), sizeof(Institute))) {
        institutes.push_back(institute);
    }

    file.close();

    // Зображуємо меню
    int choice;
    do {
        cout << "\nChoose an action:\n";
        cout << "1. Add data\n";
        cout << "2. Replace data\n";
        cout << "3. Delete data\n";
        cout << "4. Add student to institute\n";
        cout << "5. Display students by course and group\n";
        cout << "6. Find faculty and group with most excellent students\n";
        cout << "7. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            Institute institute;
            cout << "Enter the institute name: ";
            cin >> institute.name;

            addDataToFile(filename, institute);
            break;
        }
        case 2: {
            int index;
            cout << "Enter the index of the record to replace: ";
            cin >> index;

            if (index >= 0 && index < institutes.size()) {
                Institute institute;
                cout << "Enter the data to replace with:\n";
                cout << "Institute name: ";
                cin >> institute.name;

                replaceDataInFile(filename, institute, index);
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 3: {
            int index;
            cout << "Enter the index of the record to delete: ";
            cin >> index;

            if (index >= 0 && index < institutes.size()) {
                deleteDataFromFile(filename, index);
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 4: {
            int instituteIndex;
            cout << "Enter the index of the institute: ";
            cin >> instituteIndex;

            if (instituteIndex >= 0 && instituteIndex < institutes.size()) {
                addStudentToInstitute(institutes[instituteIndex]);
            }
            else {
                cout << "Invalid institute index!" << endl;
            }
            break;
        }
        case 5: {
            int course;
            string group;
            cout << "Enter course: ";
            cin >> course;
            cout << "Enter group: ";
            cin >> group;

            displayStudentsByCourseAndGroup(institutes, course, group);
            break;
        }
        case 6: {
            findBestFacultyAndGroup(institutes);
            break;
        }
        case 7:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice != 7);

    return 0;
}


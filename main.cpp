#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    float cgpa;

    Student(int i, string n, float c) {
        id = i;
        name = n;
        cgpa = c;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", CGPA: " << cgpa << endl;
    }
};

vector<Student> students;

void addStudent() {
    int id;
    string name;
    float cgpa;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter CGPA: ";
    cin >> cgpa;

    students.push_back(Student(id, name, cgpa));
    cout << "Student added successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    for (auto &s : students) {
        s.display();
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto &s : students) {
        if (s.id == id) {
            cout << "Student found:\n";
            s.display();
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
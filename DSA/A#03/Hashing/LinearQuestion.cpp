#include <iostream>
#include<string>
using namespace std;

class student {
public:
    int roll;
    string name;
    double cgpa;
    int size;
    int* table;


public:
    student() :roll(-1), name(" "), cgpa(0.0) {}
    student(int r, string n, double g) {
        roll = r;
        name = n;
        cgpa = g;
    }
};


class HashTable {
private:
    int size;
    student* table;

public:
    HashTable(int s) {
        size = s;
        table = new student[size];
    }

    int hashFunc(int key) {
        return key % size;
    }

    void insert(int roll, string name, int gpa) {
        int index = hashFunc(roll);

        for (int i = 0;i < size;i++) {
            int probeIndex = (index + i) % size;
            //uncomment below line for quadratic probing and comment above line
                //int probeIndex = (index + i*i) % size; //quadratic probing
            if (table[probeIndex].roll == -1) {
                table[probeIndex] = student(roll, name, gpa);
                cout << "Student with Roll No " << roll << " inserted at index " << probeIndex << endl;
                return;
            }
        }
        cout << "Hash table is full, could not insert student with Roll No " << roll << endl;

    }

    void search(int key) {
        int index = hashFunc(key);
        for (int i = 0;i < size;i++) {
            int probeIndex = (index + i) % size;
            //uncomment below line for quadratic probing and comment above line
                //int probeIndex = (index + i*i) % size; //quadratic probing
            if (table[probeIndex].roll == -1) {
                cout << "Empty Index!!\n";
                return;
            }
            if (table[index].roll == key) {
                cout << "Student Found: || Roll Num: " << table[index].roll << " || Name: " << table[index].name << " || CGPA: " << table[index].cgpa<<endl;
                return;
            }
        }
    }


    void remove(int roll) {
        int index = hashFunc(roll);
            for (int i = 0;i < size;i++) {
                int probeIndex = (index + i) % size; //linear probing
                //uncomment below line for quadratic probing and comment above line
                //int probeIndex = (index + i*i) % size; //quadratic probing

                if (table[probeIndex].roll == -1) {
                    cout << "Empty!!\n";
                    return;
                }
                if (table[probeIndex].roll == roll) {
                    table[probeIndex].roll = -1;
                    table[probeIndex].name = "";
                    table[probeIndex].cgpa = 0.0;
                    cout << "Removed the Student!!";
                    return;
                }
            }
        }


    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (table[i].roll == -1) {
                cout << i << ": EMPTY" << endl;
            }
            else {
                cout << i << ": " << " Roll Num: " << table[i].roll << " || Name: " << table[i].name << " || CGPA: " << table[i].cgpa << endl;
            }
        }
    }


    // Destructor
    ~HashTable() {
        delete[] table;
    }


};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice, roll, cgpa;
    string name;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll Num to insert: ";
            cin >> roll;

            cout << "Enter Name to insert: ";
            cin >> name;

            cout << "Enter CGPA to insert: ";
            cin >> cgpa;


            ht.insert(roll, name, cgpa );
            break;
        case 2:
            cout << "Enter roll num to search: ";
            cin >> roll;
            ht.search(roll);
            break;
        case 3:
            cout << "Enter student roll num to delete: ";
            cin >> roll;
            ht.remove(roll);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    system("pause");
    return 0;
}

#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;      // Array to store hash table
    int size;        // Current size of the hash table
    int count;       // Number of elements in the hash table
    const int EMPTY = -1; // Sentinel value for empty slots

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Rehash function to resize the table
    void rehash() {
        cout << "Rehashing...\n";
        int oldSize = size;
        size *= 2; // Double the size
        int* oldTable = table; //make new array for storing old array

        table = new int[size]; //update the array to new size
        for (int i = 0; i < size; i++) {
            table[i] = EMPTY; // Initialize new table slots to EMPTY
        }

        count = 0;//reset count variable
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != EMPTY) {
                insert(oldTable[i]); // Reinsert existing keys
            }
        }

        delete[] oldTable; // Free memory of old table
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = EMPTY;
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Insert a key into the hash table
    void insert(int key) {
        if (count / size > 0.7) { // Check load factor (> 70%)
            rehash();
        }

        int index = hashFunction(key);

        // Linear probing to find an empty slot
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (table[probeIndex] == EMPTY) {
                table[probeIndex] = key;
                count++;
                cout << "Inserted " << key << " at index " << probeIndex << endl;
                return;
            }
        }

        cout << "Hash table is full. Cannot insert " << key << endl;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY) {
                cout << i << ": EMPTY" << endl;
            }
            else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main() {
    int size;
    cout << "Enter initial size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice, key;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Display\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            ht.display();
            break;
        case 3:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

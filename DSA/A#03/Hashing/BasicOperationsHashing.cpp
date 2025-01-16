#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;      // Array to store hash table
    int size;        // Size of the hash table
    int EMPTY;       // Sentinel value for empty slots

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table = new int[size];
        EMPTY = -1;  // Set empty slots to -1
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
        int index = hashFunction(key);

        // Linear probing to find an empty slot
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (table[probeIndex] == EMPTY) {
                table[probeIndex] = key;
                cout << "Inserted " << key << " at index " << probeIndex << endl;
                return;
            }
        }

        cout << "Hash table is full. Cannot insert " << key << endl;
    }

    // Search for a key in the hash table
    bool search(int key) {
        int index = hashFunction(key);

        // Linear probing to search for the key
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (table[probeIndex] == EMPTY) {
                return false; // Key not found
            }
            if (table[probeIndex] == key) {
                return true; // Key found
            }
        }

        return false; // Key not found after full loop
    }

    // Delete a key from the hash table
    void remove(int key) {
        int index = hashFunction(key);

        // Linear probing to find the key
        for (int i = 0; i < size; i++) {
            int probeIndex = (index + i) % size;
            if (table[probeIndex] == EMPTY) {
                cout << "Key " << key << " not found in hash table." << endl;
                return;
            }
            if (table[probeIndex] == key) {
                table[probeIndex] = EMPTY;
                cout << "Key " << key << " removed from index " << probeIndex << endl;
                return;
            }
        }

        cout << "Key " << key << " not found in hash table." << endl;
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
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    int choice, key;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            ht.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (ht.search(key)) {
                cout << "Key " << key << " found in hash table." << endl;
            }
            else {
                cout << "Key " << key << " not found in hash table." << endl;
            }
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.remove(key);
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

    return 0;
}

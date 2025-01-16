#include <iostream>
using namespace std;

class HashTable {
private:
    int* table; // Array to store hash table
    int size;   // Size of the hash table
    const int EMPTY = -1; // Marker for empty slots

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = EMPTY;
        }
    }

    ~HashTable() {
        delete[] table;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int hashIndex = hashFunction(key);
        int probeIndex;

        for (int i = 0; i < size; i++) {
            probeIndex = (hashIndex + i * i) % size; // Quadratic probing formula
            if (table[probeIndex] == EMPTY) {
                table[probeIndex] = key;
                return;
            }
        }

        cout << "Hash Table is Full, cannot insert key: " << key << endl;
    }

    bool search(int key) {
        int hashIndex = hashFunction(key);
        int probeIndex;

        for (int i = 0; i < size; i++) {
            probeIndex = (hashIndex + i * i) % size; // Quadratic probing formula
            if (table[probeIndex] == EMPTY) {
                return false; // Key not found
            }
            if (table[probeIndex] == key) {
                return true; // Key found
            }
        }

        return false; // Probed entire table
    }

    void remove(int key) {
        int hashIndex = hashFunction(key);
        int probeIndex;

        for (int i = 0; i < size; i++) {
            probeIndex = (hashIndex + i * i) % size; // Quadratic probing formula
            if (table[probeIndex] == EMPTY) {
                cout << "Key not found: " << key << endl;
                return;
            }
            if (table[probeIndex] == key) {
                table[probeIndex] = EMPTY;
                return;
            }
        }

        cout << "Key not found: " << key << endl;
    }

    void display() {
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
    HashTable ht(10);

    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    ht.display();

    return 0;
}

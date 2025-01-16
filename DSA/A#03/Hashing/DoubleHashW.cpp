#include <iostream>
using namespace std;

class DoubleHashing {
private:
    int* table;
    int size;
    int capacity;
    int empty;

public:
    DoubleHashing(int s) {
        size = s;
        table = new int[size];
        empty = -1;

        for (int i = 0;i < size;i++) {
            table[i] = empty;
        }
    }

    int primaryHashFunc(int key) {
        return key % size;
    }

    int secondaryHashFunc(int key) {
        return key % (size - 1);
    }

    void insert(int key) {
        int primIndex = primaryHashFunc(key);
        int secIndex = secondaryHashFunc(key);

        for (int i = 0;i < size;i++) {
            int probeIndex = (primIndex + i * secIndex) % size;
            if (table[probeIndex] == empty) {
                table[probeIndex] = key;
                cout << "Inserted " << key << " at " << probeIndex << endl;
                return;
            }
        }
        cout << "Hash table is full. Cannot insert " << key << endl;
    }

    bool search(int key) {
        int primIndex = primaryHashFunc(key);
        int secIndex = secondaryHashFunc(key);

        for (int i = 0;i < size;i++) {
            int probeIndex = (primIndex + i * secIndex) % size;
            if (table[probeIndex] == empty) {
                return false;
            }
            else {
                return true;
            }
        }
        return false;
    }

    void deleteKey(int key) {
        int primIndex = primaryHashFunc(key);
        int secIndex = secondaryHashFunc(key);

        for (int i = 0;i < size;i++) {
            int probeIndex = (primIndex + i * secIndex) % size;

            if (table[probeIndex] == empty) {
                cout << "Key " << key << "not found in the hash table\n";
                return;
            }

            if (table[probeIndex] == key) {
                table[probeIndex] = empty;
                return;
            }
        }
        cout << "Key " << key << "not found in the hash table\n";
    }

    void display() {
        cout << "Displaying Hash Table:\n";
        for (int i = 0;i < size;i++) {
            if (table[i] == empty) {
                cout << i << ": Empty\n";
            }
            else {
                cout << i << ": " << table[i] << endl;
            }
        }
    }


};


int main() {
    DoubleHashing Lh(10);

    Lh.insert(33);
    Lh.insert(44);
    Lh.insert(67);
    Lh.insert(89);
    Lh.insert(92);
    Lh.insert(47);
    Lh.insert(97);
    Lh.insert(20);
    Lh.insert(40);

    if (Lh.search(92)) {
        cout << "Value found\n";
    }

    Lh.display();

    system("pause");
    return 0;
}
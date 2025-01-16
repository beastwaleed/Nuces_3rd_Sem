#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct HashNode {
	int ID;
	string Name;

	HashNode() : ID(-1), Name("") {}		// Default to an empty bucket
	HashNode(int id, string n) : ID(id), Name(n) {}
};

// Hash map using quadratic probing
class Quadratic {
	vector<HashNode> table;
	int size, capacity;

	int hashFunction(int key) const {
		int hash = key % capacity;
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

	bool search(int key, int& returnIndex) {
		if (size == 0)
			return false;

		int index = hashFunction(key);
		int start = index, i = 1;
		bool flag = 0;

		while (true) {
			if (table[start].ID == key) {
				returnIndex = start;
				return true;
			}

			if (table[start].ID == -1)
				return false;

			if (i == capacity)
				return false;

			if (flag) {
				start = (key + (i * i)) % capacity;
				flag = false;
			}

			else {
				start = (key - (i * i)) % capacity;
				i++;
				flag = true;
			}
		}
	}

public:
	Quadratic(int c) {
		size = 0;
		capacity = c;
		table.resize(c, HashNode());
	}

	bool insert(int key, const string& n) {
		if (size >= capacity) {
			cout << "Hash table is full. Cannot insert key: " << key << endl;
			return false;
		}

		int index = hashFunction(key);
		int start = index, i = 0;
		bool flag = false;		// true = +ve : false = -ve

		while (true) {	// Loop while bucket is neither empty nor deleted
			if (table[start].ID == key) { // Key already exists
				cout << "Duplicate key: " << key << ". Insertion skipped." << endl;
				return false;
			}

			if (table[start].ID == -1 || table[start].ID == -2) {
				table[start] = HashNode(key, n);
				size++;
				return true;
			}

			if (i == capacity) { // Full cycle through the table
				cout << "No available slot for key: " << key << endl;
				return false;
			}

			if (flag) {
				start = (key + (i * i)) % capacity;
				flag = false;
			}

			else {
				start = (key - (i * i)) % capacity;
				i++;
				flag = true;
			}

		}
	}

	bool remove(int key) {
		int index = 0;

		if (!search(key, index))
			return false;

		table[index] = HashNode(-2, "");
		size--;
		return true;
	}

	bool search(int key) {
		int x;
		return (search(key, x));
	}

	void display() {
		cout << "\nHash Table:" << endl;
		for (int i = 0; i < capacity; i++) {
			if (table[i].ID == -1) {
				cout << i << ": Empty" << endl;
			}
			else if (table[i].ID == -2) {
				cout << i << ": Deleted" << endl;
			}
			else {
				cout << i << ": (" << table[i].ID << ", " << table[i].Name << ")" << endl;
			}
		}
	}

};

int main() {
	Quadratic ht(11); // Table of size 11

	ht.insert(10, "Book A");
	ht.insert(22, "Book B");
	ht.insert(31, "Book C");
	ht.insert(4, "Book D");
	ht.insert(15, "Book E");
	ht.insert(28, "Book F");
	ht.insert(17, "Book G");
	ht.insert(88, "Book H");
	ht.insert(59, "Book I");

	ht.display();

	cout << "\nSearch key 31: " << ht.search(31) << endl;
	cout << "Search key 100: " << ht.search(100) << endl;

	cout << "\nRemoving key 28: " << (ht.remove(28) ? "Removed" : "Not Found") << endl;
	ht.display();

	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

struct HashNode {
	int ID;
	string Name;

	HashNode() : ID(-1), Name("") {}
	HashNode(int id, const string& n) : ID(id), Name(n) {}
};

class Double {
	vector<HashNode> table;
	int size, capacity;

	int primaryHash(int key) const {
		int hash = key % capacity;
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

	int secondaryHash(int key) const {
		int hash = 1 + (key % (capacity - 1));
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

	bool search(int key, int& returnIndex) {
		if (size == 0)
			return false;

		int index = primaryHash(key);
		int i = 0;
		while (true) {
			if (i == capacity)
				return false;
			if (table[index].ID == key) {
				returnIndex = index;
				return true;
			}
			index = (primaryHash(key) + i * secondaryHash(key)) % capacity;
			i++;
		}
	}

public:
	Double(int c) {
		capacity = c;
		size = 0;
		table.resize(c, HashNode());
	}

	bool insert(int key, const string& n) {
		if (key < 1)
			return false;

		int index = primaryHash(key);
		int start = index;
		int i = 0;

		while (true) {
			if (i == capacity)
				return false;
			if (table[start].ID == -1 || table[start].ID == -2) {
				table[start] = HashNode(key, n);
				size++;
				return true;
			}
			if (table[start].ID == key)
				return false;
			start = (primaryHash(key) + i * secondaryHash(key)) % capacity;
			i++;
		}

	}

	bool search(int key) {
		int x;
		return (search(key, x));
	}

	bool remove(int key) {
		int index = 0;

		if (!search(key, index))
			return false;

		table[index] = HashNode(-2, "");
		size--;
		return true;
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
	Double ht(11); // Table of size 11

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
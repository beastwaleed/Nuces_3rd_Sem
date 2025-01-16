#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HashNode {
	int ID;
	string Name;

	HashNode() : ID(-1), Name("") {}		// Default to an empty bucket
	HashNode(int id, string n) : ID(id), Name(n) {}
};

// Linear Probing (Open Addressing)
class HashTable {
	vector<HashNode> table;
	int size;

	int hashFunction(int key) const {
		int hash = key % size;
		if (hash < 0)
			return (hash + size);		// For negative key values
		else
			return hash;
	}

	bool search(int key, int& returnIndex) {
		int index = hashFunction(key);

		if (table[index].ID == key) {
			returnIndex = index;
			return true;
		}

		int start = index;

		while (table[index].ID != key) {
			start = (start + 1) % size;

			if (table[index].ID != -1)
				return false;

			if (start == index)
				return false;
		}

		returnIndex = start;
		return true;
	}

public:
	HashTable(int s) {
		size = s;
		table.resize(size, HashNode());  // Initialize all buckets as empty
	}

	bool insert(int key, const string& name) {
		int index = hashFunction(key);

		if (table[index].ID == -1 || table[index].ID == -2) {
			table[index] = HashNode(key, name);
			return true;
		}

		int start = index;

		while (table[start].ID != -1 && table[start].ID != -2) {	// Loop while the bucket is neither empty nor deleted
			start = (start + 1) % size;		// Circular array - Linear Probing

			if (start == index)
				return false;
		}

		table[start] = HashNode(key, name);
		return true;
	}

	bool search(int key) {
		int x;
		return (search(key, x));
	}

	bool remove(int key) {
		int index = 0;
		if (!search(key, index))
			return false;

		table[index] = HashNode(-2, "");	// -2 = deleted
		return true;
	}

	void display() {
		cout << "\n\tID\tName"
			<< "\n-----------------";
		for (int i = 0; i < size; i++) {
			if (table[i].ID == -1) {
				cout << "\n" << i << " : " << "\tEMPTY";
				continue;
			}
			if (table[i].ID == -2) {
				cout << "\n" << i << " : " << "\tDELETED";
				continue;
			}

			cout << "\n" << i << " : " << table[i].ID << "\t" << table[i].Name;
		}
	}

};

int main() {
	HashTable map(10);


	map.insert(582, "Jack7");
	map.insert(311, "Jack6");
	map.insert(56, "Jack5");
	map.insert(52, "Jack4");
	map.insert(82, "Jack3");
	map.insert(117, "Jack2");
	map.insert(3, "Jack");

	map.display();

	if (map.search(582))
		cout << "ID Found!" << endl;
	else
		cout << "ID NOT Found!" << endl;

	system("pause");
	return 0;
}
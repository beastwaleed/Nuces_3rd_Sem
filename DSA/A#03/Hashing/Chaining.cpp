#include <iostream>
#include <vector>
using namespace std;

struct HashNode {
	int data;
	HashNode* next;

	HashNode() : data(-1), next(NULL) {}
	HashNode(int val) : data(val), next(NULL) {}
};

class CatalogChaining {
	int size, capacity;
	vector<HashNode*> table;


	int primaryHash(int key) const {
		int hash = key % capacity;
		if (hash < 0)
			return (hash + capacity);
		else
			return hash;
	}

public:
	CatalogChaining(int c) {
		capacity = c;
		size = 0;
		table.resize(capacity, NULL);
	}

	bool insertChain(int key) {
		int index = primaryHash(key);
		HashNode* newNode = new HashNode(key);
		if (table[index] == NULL) {
			table[index] = newNode;
			size++;
			return true;
		}

		HashNode* current = table[index];

		while (current->next != NULL) {
			if (current->data == key)
				return false;
			current = current->next;
		}

		current->next = newNode;
		size++;
		return true;
	}


	bool search(int key) {
		int index = primaryHash(key);
		HashNode* current = table[index];

		while (current != NULL) {
			if (current->data == key)
				return true;
			current = current->next;
		}
		return false;
	}

	void display() {
		for (int i = 0; i < capacity; i++) {
			cout << i << ": ";
			HashNode* current = table[i];
			while (current != NULL) {
				cout << current->data << " -> ";
				current = current->next;
			}
			cout << "NULL\n";
		}
	}

	~CatalogChaining() {
		for (int i = 0; i < capacity; i++) {
			HashNode* current = table[i];
			while (current != NULL) {
				HashNode* temp = current;
				current = current->next;
				delete temp;
			}
		}
	}
};


int main() {
	CatalogChaining cc(15);
	vector<int> values = { 17, 26, 15, 9, 11, 43, 75, 19, 35, 45, 55, 9, 10, 21, 61, 23 };

	for (int p : values) {
		cc.insertChain(p);
	}

	if (cc.search(15)) {
		cout << "Value Found\n";
	}

	cout << "\nChaining Hash Table:\n";
	cc.display();

	system("pause");
	return 0;
}

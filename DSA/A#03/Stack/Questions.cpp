#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(const string& d) : data(d), next(nullptr) {}
};

class Stack {
    Node* top;
    int currSize;

public:
    Stack() : top(nullptr), currSize(0) {}

    bool isEmpty() const {
        return top == nullptr;
    }

    void push(const string& value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        ++currSize;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        --currSize;
    }

    string peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return "";
        }
        return top->data;
    }

    int size() const {
        return currSize;
    }
};

class TextEditor {
    Stack undoStack;
    Stack redoStack;
    string currentText;

public:
    void insertText(const string& text) {
        undoStack.push(currentText);
        currentText += text;
        while (!redoStack.isEmpty()) {
            redoStack.pop();
        }
    }

    void deleteText(int length) {
        if (length <= currentText.length()) {
            undoStack.push(currentText);
            currentText.erase(currentText.length() - length, length);
            while (!redoStack.isEmpty()) {
                redoStack.pop();
            }
        }
        else {
            cout << "Delete length exceeds current text length!" << endl;
        }
    }

    void alterText(const string& newText) {
        undoStack.push(currentText);
        currentText = newText;
        while (!redoStack.isEmpty()) {
            redoStack.pop();
        }
    }

    void undo() {
        if (!undoStack.isEmpty()) {
            redoStack.push(currentText);
            currentText = undoStack.peek();
            undoStack.pop();
        }
        else {
            cout << "Nothing to undo!" << endl;
        }
    }

    void redo() {
        if (!redoStack.isEmpty()) {
            undoStack.push(currentText);
            currentText = redoStack.peek();
            redoStack.pop();
        }
        else {
            cout << "Nothing to redo!" << endl;
        }
    }

    string getText() const {
        return currentText;
    }
};

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Insert Text" << endl;
    cout << "2. Delete Text" << endl;
    cout << "3. Alter Text" << endl;
    cout << "4. Undo" << endl;
    cout << "5. Redo" << endl;
    cout << "6. Display Text" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    TextEditor editor;
    int choice;
    string text;
    int length;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter text to insert: ";
            cin.ignore();
            getline(cin, text);
            editor.insertText(text);
            break;
        case 2:
            cout << "Enter length of text to delete: ";
            cin >> length;
            editor.deleteText(length);
            break;
        case 3:
            cout << "Enter new text to replace current text: ";
            cin.ignore();
            getline(cin, text);
            editor.alterText(text);
            break;
        case 4:
            editor.undo();
            break;
        case 5:
            editor.redo();
            break;
        case 6:
            cout << "Current Text: " << editor.getText() << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}

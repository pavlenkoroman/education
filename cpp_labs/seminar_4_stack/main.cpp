#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *topNode;

    void initialize() {
        topNode = nullptr;
    }

    void push(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (is_empty()) {
            cout << "Стек пуст. Невозможно выполнить операцию pop()." << endl;
            return;
        }

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() {
        if (is_empty()) {
            cout << "Стек пуст. Невозможно выполнить операцию top()." << endl;
            return 0;
        }

        return topNode->data;
    }

    bool is_empty() {
        return topNode == nullptr;
    }
} Stack;

int main() {
    setlocale(LC_ALL, "Russian");

    Stack stack;
    stack.initialize();

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Верхушка: " << stack.top() << endl;

    stack.pop();

    cout << "Верхушка после pop: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    if (stack.is_empty()) {
        cout << "Стек пуст." << endl;
    } else {
        cout << "Стек не пуст." << endl;
    }

    return 0;
}

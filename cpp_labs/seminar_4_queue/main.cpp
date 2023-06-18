#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

struct Queue {
    Node *head;
    Node *tail;

    void push(int value) {
        Node *new_node = new Node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (tail == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    int pop() {
        if (head == nullptr) {
            return -1;
        }

        int value = head->value;
        Node *old_head = head;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete old_head;
        return value;
    }

    int front() {
        if (head == nullptr) {
            return -1;
        }

        return head->value;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Queue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "front() - ";
    cout << queue.front() << endl;

    cout << "pop() - ";
    cout << queue.pop() << endl;

    cout << "pop() - ";
    cout << queue.pop() << endl;

    cout << "front() - ";
    cout << queue.front() << endl;

    return 0;
}

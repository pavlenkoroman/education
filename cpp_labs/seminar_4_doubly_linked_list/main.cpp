#include <iostream>

using namespace std;

typedef struct Node {
    int value;
    Node *prev;
    Node *next;
} Node;

typedef struct LinkedList{
    int size;
    Node *head;
    Node *tail;
} LinkedList;

LinkedList *create_linked_list();

void delete_linked_list(LinkedList **list);

void push_front(LinkedList *list, int value);

int pop_front(LinkedList *list);

void push_back(LinkedList *list, int value);

int pop_back(LinkedList *list);

Node *get_linked_list_element(LinkedList *list, int index);

void print_linked_list(LinkedList *list);

int main() {
    setlocale(LC_ALL, "Russian");

    LinkedList *linked_list = create_linked_list();
    push_front(linked_list, 1);
    push_front(linked_list, 2);
    push_front(linked_list, 3);
    push_back(linked_list, 4);
    push_back(linked_list, 5);
    push_back(linked_list, 6);

    print_linked_list(linked_list);

    cout << "pop front - " << pop_front(linked_list) << endl;
    cout << "pop back - " << pop_back(linked_list) << endl;

    cout << "Элемент с индексом 3 - " << get_linked_list_element(linked_list, 3)->value << endl;

    print_linked_list(linked_list);

    delete_linked_list(&linked_list);

    cout << "Лист удалён. Повертье на слово!" << endl;
}

LinkedList *create_linked_list() {
    auto *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = list->tail = nullptr;

    return list;
}

void delete_linked_list(LinkedList **list) {
    Node *tmp = (*list)->head;
    Node *next = nullptr;

    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }

    free(*list);
    (*list) = nullptr;
}

void push_front(LinkedList *list, int value) {
    Node *node = (Node *) malloc(sizeof(Node));

    node->value = value;
    node->next = list->head;
    node->prev = nullptr;

    if (list->head) {
        list->head->prev = node;
    }

    list->head = node;

    if (list->tail == nullptr) {
        list->tail = node;
    }

    list->size++;
}

int pop_front(LinkedList *list) {
    Node *prev;
    int tmp;

    prev = list->head;
    list->head = list->head->next;

    if (list->head) {
        list->head->prev = nullptr;
    }

    if (prev == list->tail) {
        list->tail = nullptr;
    }

    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

void push_back(LinkedList *list, int value) {
    Node *tmp = (Node *) malloc(sizeof(Node));

    if (tmp == nullptr) {
        exit(3);
    }

    tmp->value = value;
    tmp->next = nullptr;
    tmp->prev = list->tail;

    if (list->tail) {
        list->tail->next = tmp;
    }

    list->tail = tmp;

    if (list->head == nullptr) {
        list->head = tmp;
    }

    list->size++;
}

int pop_back(LinkedList *list) {
    Node *next;
    int tmp;

    next = list->tail;
    list->tail = list->tail->prev;

    if (list->tail) {
        list->tail->next = nullptr;
    }

    if (next == list->head) {
        list->head = nullptr;
    }

    tmp = next->value;
    free(next);

    list->size--;
    return tmp;
}

Node *get_linked_list_element(LinkedList *list, int index) {
    Node *tmp = list->head;

    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}

void print_linked_list(LinkedList *list) {
    Node *node = list->head;

    while (node != nullptr) {
        cout << node->value << " ";
        node = node->next;
    }

    printf("\n");
}
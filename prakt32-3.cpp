#include <iostream>
void sort();
void remove_duplicates();

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {

public:
    Node* head, * tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    };

    void push_front(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        }
        if (tail == nullptr)
        {
            tail = newNode;
        }

        head = newNode;

    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        newNode->prev = tail;

        if (tail != nullptr) {
            tail->next = newNode;
        }
        if (head == nullptr) {
            head = newNode;
        }

        tail = newNode;

    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        Node* newNode = head;
        head = head->next;

        if (head == nullptr) {
            tail == nullptr;
        }
        else
        {
            head->prev = nullptr;
        }

    }

    void pop_back() {
        if (tail == nullptr) return;
        Node* newNode = tail;
        tail = tail->prev;

        if (tail == nullptr) {
            head = nullptr;
        }
        else {
            tail->next = nullptr;
        }
        delete newNode;
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    void sort()
    {
        if (head == nullptr) return;
        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);

    }
    void remove_duplicates()
    {
        if (head == nullptr)
            return;

        Node* cur = head;
        while (cur != nullptr) {
            Node* curnode = cur;
            while (curnode->next != nullptr) {
                if (cur->data == curnode->next->data) {
                    Node* temp = curnode->next;
                    curnode->next = curnode->next->next;
                    if (curnode->next != nullptr) {
                        curnode->next->prev = curnode;
                    }
                    else {
                        tail = curnode;
                    }
                    delete temp;
                }
                else {
                    curnode = curnode->next;
                }
            }
            cur = cur->next;
        }

    };

};
void main()
{
    setlocale(0, "rus");

    DoublyLinkedList list;
    int number;
    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1 - Добавить элемент в начало списка" << endl;
        cout << "2 - Добавить элемент в конец списка" << endl;
        cout << "3 - Убрать элемент из начала списка" << endl;
        cout << "4 - Убрать элемент с конца списка" << endl;
        cout << "5 - Отобразить список" << endl;
        cout << "6 - Отсортировать список" << endl;
        cout << "7 - Удалить дубликаты" << endl;
        cout << "8 - Выход" << endl;

        cin >> number;

        switch (number) {
        case 1:
            cout << "Введите значение: ";
            cin >> number;
            list.push_front(number);
            break;
        case 2:
            cout << "Введите значение: ";
            cin >> number;
            list.push_back(number);
            break;
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            list.display();
            break;
        case 6:
            list.sort();
            break;
        case 7:
            list.remove_duplicates();
            break;
        case 8:
            return;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}
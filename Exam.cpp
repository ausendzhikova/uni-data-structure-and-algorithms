#include <iostream>
#include <string>
#include <list>
#include <iterator>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

struct myLinkedList {
    Node* head;
    Node* tail;
    Node* middle;
    unsigned int size;

    myLinkedList() {
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        size = 0;
    };

    void push_back(int pistolsNum) {
        Node* nodeToAdd = new Node(pistolsNum,tail);
        size++;
        if (!tail) {
            head = middle = tail = nodeToAdd;
        }
        else {
            tail->next = nodeToAdd;
            tail = nodeToAdd;
            if (size % 2 == 0) {
                middle = middle->next;
            }
        }
    }

    void pop_back() {
        //Not Empty linked list
        if (tail) {
            tail = tail->prev;
            size--;

            //After pop_back linked list is empty
            if (!tail) {
                head = nullptr;
                middle = nullptr;
            }
            // After pop_back linked list is not empty
            else {
                tail->next = nullptr;
                if (size % 2 != 0) {
                    middle = middle->prev;
                }
            }

        }
    }

    void capturedByMilen() {
        if (size <= 1) {
            return;
        }
        Node* prevHead(head);
        Node* prevMiddle(middle);
        Node* prevTail(tail);
        head->prev = tail;
        tail->next = head;
        head = prevMiddle;
        tail = prevMiddle->prev;
        if (size % 2 !=0) {
            middle = prevTail;
        }
        else {
            middle = prevHead;
        }

        head->prev = nullptr;
        tail->next = nullptr;
    }

};

void printResult(myLinkedList& linkedListPistols) {
    Node* start = linkedListPistols.head;
    cout << linkedListPistols.size << endl;
    while (start != nullptr) {
        cout << start->data << " ";
        start=start->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    myLinkedList linkedListPistols;

    for (int i = 0; i < n; i++) {
        string input;
        int pistolsNum;
        cin >> input;
        if (input == "add") {
            cin >> pistolsNum;
            linkedListPistols.push_back(pistolsNum);
        }
        else if (input == "gun") {
            linkedListPistols.pop_back();
        }
        else if (input == "milen") {
            linkedListPistols.capturedByMilen();
        }
    }

    printResult(linkedListPistols);
    return 0;
}
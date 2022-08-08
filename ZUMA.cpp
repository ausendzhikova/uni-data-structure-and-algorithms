#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

struct Node {
    int value;
    int num;
    Node* prev;
    Node* next;

    Node(int value, int num, Node* prev = nullptr, Node* next = nullptr) {
        this->value = value;
        this->num = num;
        this->prev = prev;
        this->next = next;
    }
};

struct myLinkedList {
    Node* head;
    Node* tail;
    int size;

    myLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void addAfterP(Node* nodeToAdd, Node* it) {
        size++;
        nodeToAdd->prev = it;
        nodeToAdd->next = it->next;
        it->next = nodeToAdd;
        if (nodeToAdd->next == nullptr) {
            tail = nodeToAdd;
            return;
        }
        nodeToAdd->next->prev = nodeToAdd;

    }

    void push_back(Node* nodeToAdd) {
        
        nodeToAdd->prev = tail;
        size++;
        if (tail == nullptr) {
            head = tail = nodeToAdd;
        }
        else {
            tail->next = nodeToAdd;
            tail = nodeToAdd;
        }
    }

    //  2 2 2 3 3 3 3 3

    void remove(Node* start, Node* end, int count) {
        if (start == head && end == tail) {
            if (start->value == end->value) {
                head = tail = nullptr;
            }
            else {
                head = tail = end;
            }
        }
        else if (start == head && end != tail) {
            head = end;
        }
        else if (start->prev != nullptr && end->next == nullptr) {

            end->prev = start->prev;
            if (start->value == end->value) {
                tail = start->prev;
                start->prev->next = nullptr;
            }
            else {
                start->prev->next = end;
                tail = end;
            }

        }
        else if (start->prev != nullptr && end->next != nullptr) {
            start->prev->next = end;
            end->prev = start->prev;
        }
        size -= count;

    }

    //  1 1 1 2 2 2  2 3 4 


    Node* findP(int p) {
        auto it = head;
        if (it->num == p) {
            return head;
        }
        while (it->next != nullptr && it->next->num != p) {
            it = it->next;
        }
        if (it->next != nullptr) {
            it = it->next;
        }
        return it;
    }


    int shoot(Node* nodeToAdd,Node* it) {
        if (size == 0) {
            return -1;
        }
        addAfterP(nodeToAdd, it);
        
        int sumCount = 0;
        while (it != nullptr) {
            if (it->next == nullptr) {
                return sumCount;
            }

            if (it->next != nullptr && it->value != it->next->value) {
                it = it->next;
            }
            auto middle = it;
            int count = 0;

            while (it->prev != nullptr && it->value == it->prev->value) {
                count++;
                it = it->prev;
            }

            Node* current = middle;

            while (current->next != nullptr && it->value == current->value) {
                count++;
                current = current->next;
            }
            if (current->prev != nullptr && current->next == nullptr && current->value == current->prev->value) {
                count++;
            }
            if (count >= 3) {
                remove(it, current, count);
                sumCount += count;
                if (current->value != current->prev->value) {
                    return sumCount;
                }
                if (current == head) {
                    return sumCount;
                }

                current = current->prev;


                if (head == nullptr) {
                    current = nullptr;
                }


            }
            else {
                return sumCount;
            }
            it = current;
        }

        return sumCount;

    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    myLinkedList balls;
    int ball;

    vector<Node*> iterators;
    for (int i = 0; i < n; i++) {
        cin >> ball;
        Node* temp = new Node(ball, i);
        balls.push_back(temp);
        iterators.push_back(balls.tail);
    }

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++) {
        int p, c;
        cin >> p >> c;
        queries[i] = (make_pair(p, c));
    }
    
    
    int num = n;
    for (int i = 0; i < q; i++) {
        Node* nodeToAdd = new  Node(queries[i].second, num);
        Node* p = iterators[queries[i].first];
        int count = balls.shoot(nodeToAdd,p);
        iterators.push_back(nodeToAdd);
        num += 1;
        if (count == -1) {
            printf("Game Over\n");
        }
        else {
            printf("%i\n", count);
        }
    }


    if (balls.size != 0) {
        auto start = balls.head;
        auto end = balls.tail->next;
        while (start) {
            printf("%i ", start->value);
            start = start->next;

        }
    }
    else {
        printf("-1\n");
    }

    return 0;
}
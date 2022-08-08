#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    int x;
    int y;

    Node(int value,int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        left = nullptr;
        right = nullptr;
    }
};

void topView(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> el;
    el.push(root);
    map<int,int> viewEl;
    while (!el.empty()) {
        auto current = el.front();
        el.pop();
        if (current->left) {
            el.push(current->left);
        }
        if (current->right) {
            el.push(current->right);
        }
        if (!viewEl.count(current->x)) {
            viewEl[current->x] = current->value;
        }
    }

    for (auto x : viewEl) {
        cout << x.second << " ";
    }

}

int main() {
    Node* root = new Node(0,0,0);
    vector<Node*> binaryTree;
    binaryTree.push_back(root);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int leftChild, rightChild;
        cin >> leftChild >> rightChild;

        if (leftChild != -1) {
            Node* left = new Node(leftChild,binaryTree[i]->x-1,binaryTree[i]->y-1);
            binaryTree[i]->left = left;
            binaryTree.push_back(left);
        }
        if (rightChild != -1) {
            Node* right = new Node(rightChild, binaryTree[i]->x+1, binaryTree[i]->y-1);
            binaryTree[i]->right = right;
            binaryTree.push_back(right);
        }
    }

    topView(binaryTree[0]);

    return 0;
}

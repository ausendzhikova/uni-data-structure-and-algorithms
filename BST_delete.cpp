#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* newNode(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return newNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node* KthLargest(Node* root,  int k,int* count)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    Node* element = KthLargest(root->right,k,count);
    if (element)
    {
        return element;
    }
    (*count)++;
    if (*count == k)
    {
        return root;
    }
    return KthLargest(root->left,k,count);
}

Node* findElementToDel(Node* root, int k)
{
    int count = 0;
    return KthLargest(root, k,&count);
}

Node* findNodeToReplace(Node* root) {
    Node* current = root;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}


Node* deleteElement(Node* root, int kValue) {
    if (root == nullptr) {
        return root;
    }
    if (kValue < root->value) {
        root->left = deleteElement(root->left, kValue);
    }
    else if (kValue > root->value) {
        root->right = deleteElement(root->right, kValue);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return root;
        }
        if (root->left == nullptr) {
            Node* node = root->right;
            delete root;
            root = node;
            return root;
        }
        if (root->right == nullptr) {
            Node* node = root->left;
            delete root;
            root = node;
            return root;
        }
        Node* node = findNodeToReplace(root->right);
        root->value = node->value;
        root->right = deleteElement(root->right, root->value);
    }
    return root;
}

void print(Node* root) {
    if (root == nullptr) {
        return;
    }
    queue<Node*> toPrint;
    toPrint.push(root);

    while (!toPrint.empty()) {
        Node* node = toPrint.front();
        toPrint.pop();
        cout << node->value << " ";


        if (node->left) {
            toPrint.push(node->left);
        }
        if (node->right) {
            toPrint.push(node->right);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;


    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int node;
        cin >> node;
        root = insert(root, node);

    }

    Node* nodeToDel = findElementToDel(root, k);
    deleteElement(root, nodeToDel->value);
    print(root);
    return 0;
}
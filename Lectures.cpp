#include <bits/stdc++.h>

using namespace std;

queue<int> findIndices(const string& lectures) {
    int size = lectures.size();
    
    int counter[128];
    for (int i = 0; i < 128; i++) {
        counter[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        counter[lectures[i]] += 1;
    }

    queue<int> indices;
    for (int i = 0; i < size; i++) {
        if (counter[lectures[i]] == 1) {
            indices.push(i);
        }
    }
    return indices;
}

int main() {
    string lectures;
    cin >> lectures;
    queue<int> indices = findIndices(lectures);

    while (!indices.empty()) {
        cout << indices.front() << " ";
        indices.pop();
    }

    return 0;
}
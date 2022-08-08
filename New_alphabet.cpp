#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<char>> alphabet;
unordered_map<char, bool> visited;
stack<char> orderedAlphabet;

void dfs(char v) {
    visited[v] = 1;
    for (auto symb : alphabet[v]) {
        if (visited[symb] == 0) {
            dfs(symb);
        }
    }
    orderedAlphabet.push(v);
}

void topologicalSort() {

    for (auto symb : alphabet) {
        char current = symb.first;
        if (visited[current] == 0) {
            dfs(current);
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> words;

    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        words.push_back(w);
    }
    vector<char> emptyVec;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            if (!alphabet.count(words[i][j])){
                alphabet.insert({ words[i][j], emptyVec});
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        string curWord = words[i];
        string nextWord = words[i + 1];
        auto size = min(curWord.size(), nextWord.size());
        for (auto j = 0; j < size; j++) {
            if (curWord[j] != nextWord[j]) {
                alphabet[curWord[j]].push_back(nextWord[j]);
                visited[curWord[j]] = 0;
                break;
            }
        }
    }

    topologicalSort();
    while (!orderedAlphabet.empty()) {
        auto current = orderedAlphabet.top();
        orderedAlphabet.pop();
        cout << current << " ";
    }

    return 0;
}
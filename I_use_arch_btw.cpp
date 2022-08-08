#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, bool> visited;

void isCyclic(int v,bool& cyclic) {
    if (visited[v] == true) {
        cyclic = true;
        return;
   }
    visited[v] = true;
    for (auto x : graph[v]) {
        isCyclic(x, cyclic);
    }
    visited[v] = false;
}

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int edgesCount;
        cin >> edgesCount;
        int start, end;
        for (int j = 0; j < edgesCount; j++) {
            cin >> start >> end;
            graph[start].push_back(end);
            visited[start] = 0;
        }

        bool cyclic = false;
        for (auto vertex : graph) {
            isCyclic(vertex.first, cyclic);
        }
        if (cyclic) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
        graph.clear();
        visited.clear();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
 vector<pair<int, int>> edgesList;
 vector<int> parent;

 int find(int vertex) {
     if (parent[vertex] == vertex) {
         return vertex;
     }
     return parent[vertex]=find(parent[vertex]);
 }

 void Union(int from,int to) {
     int rootFrom = find(from);
     int rootTo = find(to);

     if (rootFrom == rootTo) {
         return;
     }
     parent[rootTo] = rootFrom;

 }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int edgesCount, vertexCount;
    cin >> vertexCount >> edgesCount;

    for (int i = 0; i < edgesCount; i++) {
        int from, to;
        cin >> from >> to;
        edgesList.push_back({ from, to });
    }

    for (int i = 0; i <= vertexCount; i++) {
        parent.push_back(i);
    }

    for (int i = 0; i < edgesCount; i++) {
        Union(edgesList[i].first, edgesList[i].second);
    }

    int queriesCount;
    cin >> queriesCount;
    for (int i = 0; i < queriesCount; i++) {
        int type, start, end;
        cin >> type >> start >> end;

        if (type == 1) {
            if (find(start) == find(end)) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        else if (type == 2) {
            Union(start, end);
        }

    }

    return 0;
}


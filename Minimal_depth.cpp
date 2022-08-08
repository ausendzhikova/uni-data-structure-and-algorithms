#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> edgeList;
int vertexCount=0;
queue<int> q;

void minDepth() {
    
    for (int i = 0; i < vertexCount; i++) {
        if (edgeList[i] == 1) {
            q.push(i);
        }
    }

    int current = 0;
    int counter = 0;

    while (vertexCount > 2) {
        counter = q.size();
        vertexCount -= counter;

        for (int i = 0; i < counter; i++) {
            current = q.front();
            q.pop();

            for (auto neighboor : graph[current]) {
                edgeList[neighboor]--;

                if (edgeList[neighboor] == 1) {
                    q.push(neighboor);
                }
            }
        }

    }
}

int main() {
    cin >> vertexCount;
    graph.resize(vertexCount);
    for (int i = 0; i < vertexCount; i++) {
        edgeList.push_back(0);
    }
    for (int i = 0; i < vertexCount - 1; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
        edgeList[from]++;
        edgeList[to]++;
    }

    minDepth();

    set<int> vertexWithMinDepth;
    while (!q.empty()) {
        vertexWithMinDepth.insert(q.front());
        q.pop();
    }

    for (auto vertex : vertexWithMinDepth) {
        cout << vertex << " ";
    }

    return 0;
}
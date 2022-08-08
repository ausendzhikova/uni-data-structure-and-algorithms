#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;

void shortestPath(int v) {
    dist[v] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,v });

    while (!pq.empty()) {
        int current = pq.top().second;
        int costTocurrent = pq.top().first;
        pq.pop();
        for (auto x : graph[current]) {
            int child = x;
            if (dist[child] < costTocurrent) continue;

            if (dist[child] > costTocurrent + 6) {
                dist[child] = costTocurrent + 6;
                pq.push({ dist[child],child });
            }
        }
    }


}

int main() {


    int queriesCount;
    cin >> queriesCount;
    for (int a = 0; a < queriesCount; a++) {

        int vertexCount, edgesCount;
        cin >> vertexCount >> edgesCount;
        graph.assign(vertexCount + 1, vector<int>());
        dist.assign(vertexCount + 1, INT_MAX);

        for (int i = 1; i <= edgesCount; i++) {
            int w = 6;
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int index;
        cin >> index;
        shortestPath(index);

        for (int i = 1; i <= vertexCount; i++) {
            if (i == index) continue;
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
            printf("%d ", dist[i]);
        }
        graph.clear();
        dist.clear();
        printf("\n");
    }
    return 0;
}
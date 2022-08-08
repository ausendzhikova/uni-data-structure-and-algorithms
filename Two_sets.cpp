#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


const int N = 100001;
vector<pair<int, int>> graph[N];
int dist[N];
unordered_map<int, int> ump;

void dijkstra(int v) {
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
    }
    dist[v] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> toVisit;
    toVisit.push({ 0,v });

    while (!toVisit.empty()) {
        int parent = toVisit.top().second;
        int weightToParent = toVisit.top().first;
        toVisit.pop();

        if (weightToParent > dist[parent]) {
            continue;
        }

        for (auto adj : graph[parent]) {
            int child = adj.first;
            int weightToChild = adj.second;

            int weight = weightToParent + weightToChild;
            if (dist[child] > weight) {
                dist[child] = weight;
                toVisit.push({ weight,child });
            }

            auto it = ump.find(child);
            if (it != ump.end()) {
                if (it->second > dist[child]) {
                    it->second = dist[child];
                }
            }
        }
    }
}

int main() {
    int vertexCount, edgesCount;
    cin >> vertexCount >> edgesCount;

    for (int i = 0; i < edgesCount; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start].push_back({ end,weight });
        graph[end].push_back({ start,weight });
    }

    int elInTCount;
    cin >> elInTCount;

    for (int i = 0; i < elInTCount; i++) {
        int numInT;
        cin >> numInT;
        graph[vertexCount].push_back({ numInT,0 });
        graph[numInT].push_back({ vertexCount,0 });
    }

    int requestsCount;
    cin >> requestsCount;
    vector<int> requests(requestsCount);
    for (int i = 0; i < requestsCount; i++) {
        cin>>requests[i];
        ump[requests[i]]=INT_MAX;
    }
    dijkstra(vertexCount);
    
    for(int i=0;i<requestsCount;i++){
        cout<<ump[requests[i]]<<"\n";
    }
    return 0;
}
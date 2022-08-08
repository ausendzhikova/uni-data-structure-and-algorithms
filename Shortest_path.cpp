#include <bits/stdc++.h>

using namespace std;

const unsigned int N = 100001;
vector<pair<long int, long int>> graph[N];
pair<long int, long int> dist[N];
const unsigned int d = pow(10, 9) + 7;

void findShortestPath(long int v) {

    for (int i = 0; i < N; i++) {
        dist[i].first = LONG_MAX;
        dist[i].second = 0;
    }

    dist[v].first = 0;
    dist[v].second = 1;

    priority_queue<pair<long int, long int>, vector<pair<long int, long int>>, greater<pair<long int, long int>>> vertexToVisit;
    vertexToVisit.push({ 0,v });
    while (!vertexToVisit.empty()) {
        long int parent = vertexToVisit.top().second;
        long int weightToParent = vertexToVisit.top().first;
        vertexToVisit.pop();

        if (weightToParent > dist[parent].first) {
            continue;
        }

        for (auto adjVertex : graph[parent]) {
            long int child = adjVertex.first;
            long int weightToChild = adjVertex.second;

            long int weight = weightToParent + weightToChild;
            if (dist[child].first > weight) {
                dist[child].first = weight;
                dist[child].second = dist[parent].second % d;
                vertexToVisit.push({ weight,child });
            }
            else if (dist[child].first == weight) {
                dist[child].second = (dist[child].second + dist[parent].second) % d;
            }
        }

    }
}

int main() {
    long int vertexCount;
    long int edgesCount;
    long int edgeWeight;
    cin >> vertexCount >> edgesCount;
    long int start, end;
    for (long int i = 0; i < edgesCount; i++) {
        cin >> start >> end >> edgeWeight;
        graph[start].push_back({ end,edgeWeight });

    }

    findShortestPath(1);

    long int shortestDist = dist[vertexCount].first;
    long int temp = dist[vertexCount].second;


    long int pathCount = 0;

    pathCount = temp;



    if (shortestDist == LONG_MAX) {
        cout << "-1 0\n";
    }
    else {
        cout << shortestDist << " " << pathCount;
    }




    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int N = 100001;
// graph.first -> endVertex
// graph.second.first -> needTime
// graph.second.second -> kg 
vector <pair<int, pair<int, int>>> graph[N];
// dist -> time
int dist[N];

void dijkstra(int v, int maxKg) {
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
    }
    dist[v] = 0;
    // toVisit.first -> time
    // toVisiti.second.first -> endVertex
    // toVisit.second.second -> kg
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> toVisit;
    toVisit.push({ 0,{v,0} });

    while (!toVisit.empty()) {
        int parent = toVisit.top().second.first;
        toVisit.pop();

        for (pair<int,pair<int,int>> adj : graph[parent]) {
            int child = adj.first;
            int childTime = adj.second.first;
            int childKg = adj.second.second;

            if (childKg<=maxKg && dist[child]>dist[parent] + childTime) {
                dist[child] = dist[parent] + childTime;
                toVisit.push({ dist[child],{child,childKg} });
            }
        }
    }
}

int minKgToLost = INT_MAX;

void binarySearch(int left, int right, int batteryCapacity, int vertexCount) {
    
    if (right >= left) {
        int mid = left + (right - left) / 2;
        dijkstra(1, mid);
        int time = dist[vertexCount];
        if (time <= batteryCapacity) {
            minKgToLost = min(minKgToLost, mid);
            return binarySearch(left,mid-1,batteryCapacity,vertexCount);
        }
        else {
            return binarySearch(mid+1, right, batteryCapacity, vertexCount);
        }
    }
    
}

int main() {

    int vertexCount, edgesCount, batteryCapacity;
    cin >> vertexCount >> edgesCount >> batteryCapacity;


    int left = INT_MAX;
    int right = 0;

    for (int i = 0; i < edgesCount; i++) {
        int start, end, kg, needTime;
        cin >> start >> end >> kg >> needTime;
        graph[start].push_back({ end,{needTime,kg} });
        
        if (left > kg) {
            left = kg;
        }
        if (right < kg) {
            right = kg;
        }
    }

    binarySearch(left,right, batteryCapacity, vertexCount);
    
    if(minKgToLost==INT_MAX){
        cout<<-1;
    }else{
        cout<<minKgToLost;
    }

    return 0;
}

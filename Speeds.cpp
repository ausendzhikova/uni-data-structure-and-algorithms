#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


const int N = 10001;
vector<pair<int, pair<int, int>>> edgesList;
vector<int> speeds;
int p[N];
int depth[N];

int edgesCount, vertexCount;


int minSpeed = INT_MAX;
int maxSpeed = INT_MIN;
int currentDiff=INT_MAX, diff=INT_MAX, currentMin=INT_MAX, currentMax=INT_MIN;


int find(int vertex) {
    if (p[vertex] == vertex) {
        return vertex;
    }
    return p[vertex] = find(p[vertex]);
}

void Union(int from, int to) {
    int rootFrom = find(from);
    int rootTo = find(to);

    if (depth[rootFrom] > depth[rootTo]) {
        p[rootTo] = rootFrom;
    }
    else {
        p[rootFrom] = rootTo;
    }

    if (depth[rootFrom] == depth[rootTo]) {
        depth[rootTo] += depth[rootFrom];
    }
}


void kruskal() {
    sort(edgesList.begin(), edgesList.end());
    
    for (int i = 1; i <= edgesCount; i++) {

        for (int i = 0; i <= vertexCount; i++) {
            p[i] = i;
            depth[i] = 0;
        }
        int from = edgesList[i].second.first;
        int to = edgesList[i].second.second;
        int speed = edgesList[i].first;
        int counter = 1;
        currentMin = speed;
        currentMax = speed;
        Union(from, to);
        for (int j = i + 1; j <= edgesCount; j++) {
            if (find(edgesList[j].second.first) != find(edgesList[j].second.second)) {
                Union(edgesList[j].second.first, edgesList[j].second.second);
                currentMax = max(currentMax, edgesList[j].first);
                
                counter++;
            }
            if (counter == vertexCount - 1) {
                break;
            }
        }
        currentDiff = currentMax - currentMin;
        if (counter == vertexCount - 1 && currentDiff<diff) {
            diff = currentDiff;
            maxSpeed = currentMax;
            minSpeed = currentMin;
        }
    }
}

int main() {

    cin >> vertexCount >> edgesCount;
    edgesList.resize(edgesCount+1);



    for (int i = 1; i <= edgesCount; i++) {
        int from, to, s;
        cin >> from >> to >> s;


        edgesList[i] = { s,{from,to} };

    }

    kruskal();

    cout << minSpeed << " " << maxSpeed;

    return 0;
}

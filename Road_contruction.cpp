#include <bits/stdc++.h>

using namespace std;

struct Road {
    int from, to,index;
    long long c1, c2;
    Road(int index, int from, int to, long long int c1, long long int c2) {
        this->index = index;
        this->from = from;
        this->to = to;
        this->c1 = c1;
        this->c2 = c2;
    }

    bool operator<(const Road& other) const {
        if (this->c1 == other.c1) {
            return c2 >= other.c2;
        }
        return this->c1 < other.c1;
    }
};

const int N = 200002;
vector<Road> edgesList;
vector<int> indices;
vector<int> p;
vector<int> depth;

int edgesCount, vertexCount;

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
        depth[rootTo]++;
    }
}

void kruskal() {
    
    for (int i = 0; i <= vertexCount; i++) {
        p.push_back(i);
        depth.push_back(0);
    }
    sort(edgesList.begin(), edgesList.end());
    
    for (auto road:edgesList) {
        if (find(road.from) != find(road.to)) {
            Union(road.from, road.to);
            indices.push_back(road.index);
            
        }
        
    }
}

int main() {
    cin >> vertexCount >> edgesCount;
    for (int i = 0; i < edgesCount; i++) {
        int from, to;
        long long c1, c2;
        cin >> from >> to >> c1 >> c2;
        edgesList.push_back(Road(i+1, from, to, c1, c2));
    }
    kruskal();

   for(auto x: indices){
       cout<<x<<"\n";
   }

    return 0;
}
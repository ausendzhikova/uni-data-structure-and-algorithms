#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;


void dfs(int v){
    visited[v]=true;
    
    for(auto x: graph[v]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main() {
    int testCount;
    cin>>testCount;
    
    for(int i=0;i<testCount;i++){
        int vertexCount,edgesCount;
        cin>>vertexCount>>edgesCount;
        int component=0;
        graph.assign(vertexCount,vector<int>());
        visited.assign(vertexCount,0);
        for(int i=0;i<edgesCount;i++){
            int from,to;
            cin>>from>>to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        
        for(int i=0;i<vertexCount;i++){
            if(!visited[i]){
                dfs(i);
                component++;
            }
        }
        printf("%d ",component);
    }
    return 0;
}

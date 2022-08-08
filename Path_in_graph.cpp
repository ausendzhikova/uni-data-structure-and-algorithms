#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int component=1;

void dfs(int v){
    visited[v]=component;
    
    for(auto x: graph[v]){
        if(!visited[x]){
            dfs(x);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
   int vertexCount,edgesCount;
    cin>>vertexCount>>edgesCount;
    graph.assign(vertexCount+1,vector<int>());
    visited.assign(vertexCount+1,0);
    
    for(int i=0;i<edgesCount;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
   }
    
    for(int i=1;i<=vertexCount;i++){
        if(!visited[i]){
            dfs(i);
            component++;
        }
    }
    
    int k;
    cin>>k;
    
    for(int i=0;i<k;i++){
        int from,to;
        cin>>from>>to;
        if(visited[from]!=visited[to]){
            cout<<0<<" ";
        }else{
            cout<<1<<" ";
        }
    }
    
    return 0;
}
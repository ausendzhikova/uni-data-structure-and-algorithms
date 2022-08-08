#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N=2001;
unordered_set<int> graph[N][N];


int main() {
    int vertexCount, edgesCount;
    cin>>vertexCount>>edgesCount;
   
    
    for(int i=0;i<edgesCount;i++){
        int from,to,w;
        cin>>from>>to>>w;
        graph[from][to].insert(w);
    }
    
    int k;
    cin>>k;
    
    unordered_set<int> forbidden;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        forbidden.insert(num);
    }
    
    int queriesCount;
    cin>>queriesCount;
    vector<int> ans;
    
    for(int i=0;i<queriesCount;i++){
        int l;
        cin>>l;
        vector<int> path(l);
        for(int i=0;i<l;i++){
            cin>>path[i];
        }
        
         bool hasValidPath=false; 
        
        for(int i=0;i<l-1;i++){
            int from=path[i];
            int to=path[i+1];
            
            hasValidPath=false;
            for(auto x:graph[from][to]){
                if(!forbidden.count(x)){
                    hasValidPath=true;
                    break;
                }
            }
            
            if(!hasValidPath) break;
           
        }
        if(!hasValidPath){
            ans.push_back(0);
        }else{
            ans.push_back(1);
        }
    }
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    return 0;
}

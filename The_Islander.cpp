#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

const int N = 100000;
const int M = 100000;
int degree[N];
bool visited[N];
vector<int> graph[N];
int vertexCount, edgesCount;

void dfs(int v) {
    visited[v] = true;
    for (auto x : graph[v]) {
        if (visited[x] == false) {
            dfs(x);
        }
    }
}


  bool isConnected() {
  for (int i = 0; i < vertexCount; i++) {

        for (int k = 0; k < vertexCount; k++) {
            visited[k] = false;
        }
        dfs(i);
        for (int j = 0; j <vertexCount; j++) {
            if (visited[j] == false) {
                return false;
            }

        }
    }
    return true;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int queriesCount;
    cin >> queriesCount;

    for (int i = 0; i < queriesCount; i++) {
        cin >> vertexCount >> edgesCount;
        for (int i = 0; i < N; i++) {
            degree[i] = 0;
        }

        for (int i = 0; i < edgesCount; i++) {
            int from, to;
            cin >> from >> to;
            degree[from]++;
            degree[to]++;
            graph[from].push_back(to);
            graph[to].push_back(from);
        } 
        
        int oddDegreeCount = 0;
            for (int i = 0; i < N; i++) {
                if (degree[i] % 2 != 0) {
                    oddDegreeCount++;
                }
            }

        if (isConnected() || oddDegreeCount==0) {
            if (oddDegreeCount == 0) {
                cout << "ecycle\n";
            }
            else if (oddDegreeCount==0 || oddDegreeCount == 2) {
                cout << "epath\n";
            }
            else {
                cout << "none\n";
            }
        }
        else {
            cout<<"none\n";
        }
        
        for(int i=0;i<N;i++){
            graph[i].clear();
            visited[i]=false;
        }
    
    }

    return 0;
}
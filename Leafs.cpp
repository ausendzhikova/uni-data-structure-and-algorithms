#include <bits/stdc++.h>

using namespace std;

const int N = 200001;
vector<int> graph[N];
bool visited[N];

void dfs(int v, int* sum) {
    visited[v] = true;

    *sum += v;

    for (auto x : graph[v]) {

        dfs(x, sum);

    }
}

int main() {
    int edgesCount, testCount;
    cin >> edgesCount >> testCount;


    for (int i = 0; i < edgesCount; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);

        visited[from] = false;
    }

    for (int i = 0; i < testCount; i++) {
        int v;
        cin >> v;
        int sum = 0;
        dfs(v, &sum);
        printf("%d\n", sum-v);
    }


    return 0;
}
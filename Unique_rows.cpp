#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;



int main() {
    int n, m;
    cin >> n >> m;
    map<vector<int>,int> um;
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        um[temp]++;
        temp.clear();

    }

    int ans = 0;
    for (auto x : um) {
        int count = x.second;
        if (count == 1) {
            ans += 1;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
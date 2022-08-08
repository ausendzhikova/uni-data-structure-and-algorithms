#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> keys;
    vector<int> doors;
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        keys.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        int door;
        cin >> door;
        doors.push_back(door);
    }

    int count = 0;
    unordered_multiset<int> collectedKeys;
    for (int i = 0; i < n; i++) {
        collectedKeys.insert(keys[i]);
        auto it = collectedKeys.find(doors[i]);
        if (it != collectedKeys.end()) {
            collectedKeys.erase(it);
        }
        else {
            count++;
        }

    }

    printf("%d\n", count);
    return 0;
}

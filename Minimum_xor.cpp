#include <bits/stdc++.h>

using namespace std;



int findMinXOR(set<int>& requests, int lastReq) {
    auto last = requests.find(lastReq);
    

    auto prev = last;
    prev--;
    auto next = last;
    next++;

    int minXOR = INT_MAX;
    int currentXOR = 0;

    if (next != requests.end()) {
        int first = lastReq ^ (*prev);
        int second = lastReq ^ (*next);
        currentXOR = min(first, second);

    }
    else {
        currentXOR = lastReq ^ (*prev);

    }

    return min(currentXOR, minXOR);

}

int main() {
    int q;
    cin >> q;
    set<int> requests;
    requests.insert(0);
    int prevMinXOR = INT_MAX;
    int currentXOR;
    vector<int> minXors;
    for (int i = 0; i < q; i++) {
        int req;
        cin >> req;
        requests.insert(req);
        currentXOR = findMinXOR(requests, req);
        if (currentXOR < prevMinXOR) {
            prevMinXOR = currentXOR;
        }
        minXors.push_back(prevMinXOR);

    }
    int size = minXors.size();
    for (int i = 0; i < size; i++) {
        cout << minXors[i] << "\n";
    }

    return 0;
}
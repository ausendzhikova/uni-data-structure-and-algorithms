#include <bits/stdc++.h>

using namespace std;

queue<int> crossBridge(vector<int> fightersForce) {
    int size = fightersForce.size();
    deque<int> positive;
    queue<int> negative;
    queue<int> results;

    int i = 0;
    while (i < size) {
        while (i < size && fightersForce[i] < 0) {
            results.push(fightersForce[i]);
            i++;
        }
        while (i < size && fightersForce[i] > 0) {
            positive.push_back(fightersForce[i]);
            i++;
        }
        while (i < size && fightersForce[i] < 0) {
            negative.push(fightersForce[i]);
            i++;
        }

        if (positive.empty() && !negative.empty()) {
            while (!negative.empty()) {
                results.push(negative.front());
                negative.pop();
            }
        }
        else if (!positive.empty() && negative.empty()) {
            while (!positive.empty()) {
                results.push(positive.front());
                positive.pop_front();
            }
        }
        else if (!positive.empty() && !negative.empty()) {

            while (!negative.empty() && !positive.empty()) {
                if (positive.back() > abs(negative.front())) {
                    negative.pop();
                }
                else if (positive.back() < abs(negative.front())) {
                    positive.pop_back();
                }
                else {
                    positive.pop_back();
                    negative.pop();
                }
            }

            
            while (!negative.empty()) {
                results.push(negative.front());
                negative.pop();
            }

        }
    }
    while (!positive.empty()) {
        results.push(positive.front());
        positive.pop_front();
    }

    return results;
}

int main() {
    int n;
    cin >> n;
    vector<int> fightersForce;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        fightersForce.push_back(temp);
    }

    queue<int> results = crossBridge(fightersForce);

    if (results.empty()) {
        cout << '\n';
    }

    while (!results.empty()) {
        cout << results.front() << " ";
        results.pop();
    }


    return 0;
}
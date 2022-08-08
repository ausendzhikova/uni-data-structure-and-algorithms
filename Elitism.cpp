#include <bits/stdc++.h>

using namespace std;

void calculateMedian(priority_queue<int, vector<int>, greater<int>>& largerEl, priority_queue<int>& smallerEl, int el, double& median) {
    int largerSize = largerEl.size();
    int smallerSize = smallerEl.size();
    
    if (largerSize == smallerSize) {
        if (el > median) {
            largerEl.push(el);
            median = largerEl.top();
            return;
        }
        smallerEl.push(el);
        median = smallerEl.top();
        return;
    }

    if (smallerSize > largerSize) {
        if (el < median) {
            largerEl.push(smallerEl.top());
            smallerEl.pop();
            smallerEl.push(el);
            median = (smallerEl.top() + largerEl.top()) / 2.0;
            return;
        }
        largerEl.push(el);
        median = (smallerEl.top() + largerEl.top()) / 2.0;
        return;
    }

    if (el > median) {
        smallerEl.push(largerEl.top());
        largerEl.pop();
        largerEl.push(el);
        median = (smallerEl.top() + largerEl.top()) / 2.0;
        return;
    }

    smallerEl.push(el);
    median = (smallerEl.top() + largerEl.top()) / 2.0;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);

    priority_queue<int, vector<int>, greater<int>> largerEl;
    priority_queue<int> smallerEl;
    double median = 0.0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        calculateMedian(largerEl, smallerEl,el,median);
        cout<<median<<"\n";
    }

    return 0;
}
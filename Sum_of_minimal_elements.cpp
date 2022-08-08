#include <bits/stdc++.h>

using namespace std;



long long int minSum(vector<int>& numbers, int d) {
    deque<int> minElementsIndx(d);
    int size = numbers.size();
    queue<int> minElements;
    
    for (int i = 0; i < d; i++) {
        while (!minElementsIndx.empty() && numbers[i] <= numbers[minElementsIndx.back()]) {
            minElementsIndx.pop_back();
        }
        minElementsIndx.push_back(i);
    }
    
    for (int i = d; i < size; i++) {
        minElements.push(numbers[minElementsIndx.front()]);
        if (!minElementsIndx.empty() && minElementsIndx.front()<=i-d) {
            minElementsIndx.pop_front();
        }
        
        while (!minElementsIndx.empty() && numbers[i] <= numbers[minElementsIndx.back()]) {
            minElementsIndx.pop_back();
            
        }
        minElementsIndx.push_back(i);
        
    }
    minElements.push(numbers[minElementsIndx.front()]);

    long long int minNumSum = 0;
    while (!minElements.empty()) {
        minNumSum += minElements.front();
        minElements.pop();
    }

    return minNumSum;
}

int main() {
    int d, n;
    cin >> n >> d;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }
    cout << minSum(numbers, d);
    return 0;
}

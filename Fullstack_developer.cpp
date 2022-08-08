#include <bits/stdc++.h>

using namespace std;

struct Task {
     int index;
     long long timeToStart;
    long long timeToPrep;

    Task(long long index, long long timeToStart = 0, long long timeToPrep = 0) {
        this->index = index;
        this->timeToStart = timeToStart;
        this->timeToPrep = timeToPrep;
        
    }

    bool operator>(const Task& other) const {
        if (this->timeToPrep == other.timeToPrep) {
            return this->index > other.index;
        }
        return this->timeToPrep > other.timeToPrep;
    }

};

    bool sortByStart(const Task& a, const Task& b)  {
        return a.timeToStart < b.timeToStart;
    }

    int main() {
        long long n;
        cin >> n;
        vector<Task> tasks;
        for (int i = 0; i < n; i++) {
            long long start, prep;
            cin >> start >> prep;
            Task toAdd = Task(i, start, prep);
            tasks.push_back(toAdd);
        }
        sort(tasks.begin(), tasks.end(), sortByStart);
        priority_queue<Task, vector<Task>, greater<Task>> pq;
        long long start = 0;
        vector<int> results(n);
        int i = 0;
        int j = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                start = max(start, tasks[i].timeToStart);
            }
            while (i < n && tasks[i].timeToStart <= start) {
                pq.push(tasks[i]);
                i++;
            }
            Task min = pq.top();
            pq.pop();
            start += min.timeToPrep;
            results[j]=min.index;
            j++;
        }
      
        for (auto r : results) {
            cout << r << " ";
        }
        return 0;
    }
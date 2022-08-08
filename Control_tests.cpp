#include <bits/stdc++.h>

using namespace std;

struct Student {
    int index;
    long long submitTime;
    long long linesCode;

    Student(long long index, long long submitTime = 0, long long linesCode = 0) {
        this->index = index;
        this->submitTime = submitTime;
        this->linesCode = linesCode;

    }

    bool operator>(const Student& other) const {
        if (this->linesCode == other.linesCode) {
            return this->index > other.index;
        }
        return this->linesCode > other.linesCode;
    }

};

bool sortByStart(const Student& a, const Student& b) {
    return a.submitTime < b.submitTime;
}

int main() {
    long long n;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; i++) {
        long long submit, lines;
        cin >> submit >> lines;
        Student toAdd = Student(i, submit, lines);
        students.push_back(toAdd);
    }
    sort(students.begin(), students.end(), sortByStart);
    priority_queue<Student, vector<Student>, greater<Student>> pq;
    long long start = 0;
    
    double time = 0;
    int i = 0;
    int j = 0;
    while (i < n || !pq.empty()) {
        if (pq.empty()) {
            start = max(start, students[i].submitTime);
        }
        while (i < n && students[i].submitTime <= start) {
            pq.push(students[i]);
            i++;
        }
        Student min = pq.top();
        pq.pop();
        time += start - min.submitTime + min.linesCode;
        start += min.linesCode;

        j++;
    }

   long long int result = time / n;
    cout << result<< endl;
    return 0;
}
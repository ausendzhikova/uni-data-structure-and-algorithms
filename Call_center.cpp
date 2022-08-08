#include <bits/stdc++.h>

using namespace std;

struct Operator {
    int index;
    bool isBusy;
    int timeToEnd;
    int timeToStart;
    int peopleCount = 0;

    Operator(int index, int timeToStart = 0, int timeToEnd = 0, bool isBusy = false) {
        this->timeToStart = timeToStart;
        this->timeToEnd = timeToEnd;
        this->index = index;
        this->isBusy = isBusy;
    }

    bool operator<(const Operator& other) const {
        return this->peopleCount < other.peopleCount;
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<Operator> operators;

    for (int i = 0; i < k; i++) {
        operators.push_back({ i,false });
    }
    vector<pair<int, int>> clients;
    
    for (int i = 0; i < n; i++) {
        bool isDone = false;
        int j = i;
        int index = j % k;
        int start, time;
        cin >> start >> time;
       
        if (operators[index].isBusy == false) {
            operators[index].timeToStart = start;
            operators[index].timeToEnd = start + time;
            operators[index].isBusy = true;
            operators[index].peopleCount += 1;
        }
        else if (operators[index].isBusy == true && start >= operators[index].timeToEnd) {
            operators[index].peopleCount += 1;
            operators[index].timeToStart = start;
            operators[index].timeToEnd = start + time;
        }
        else {
            int copy = index+1;
            while (copy < k) {
                
                
                isDone = false;
                if (operators[copy].isBusy == false) {
                    isDone = true;
                    operators[copy].timeToStart = start;
                    operators[copy].timeToEnd = start + time;
                    operators[copy].isBusy = true;
                    operators[copy].peopleCount += 1;
                }
                else if (operators[copy].isBusy == true && start >= operators[copy].timeToEnd) {
                    isDone = true;
                    operators[copy].peopleCount += 1;
                    operators[copy].timeToStart = start;
                    operators[copy].timeToEnd = start + time;
                }
                copy++;
                if (isDone == true) {
                    break;
                }
                
            }
            if (isDone == false) {
                copy = 0;
                while (copy < index) {
                    isDone = false;
                    if (operators[copy].isBusy == false) {
                        isDone = true;
                        operators[copy].timeToStart = start;
                        operators[copy].timeToEnd = start + time;
                        operators[copy].isBusy = true;
                        operators[copy].peopleCount += 1;
                    }
                    else if (operators[copy].isBusy == true && start >= operators[copy].timeToEnd) {
                        isDone = true;
                        operators[copy].peopleCount += 1;
                        operators[copy].timeToStart = start;
                        operators[copy].timeToEnd = start + time;
                    }
                    copy++;
                    if (isDone == true) {
                        break;
                    }
                }
            }
            clients.push_back({ start,time });
        }
    }
    make_heap(operators.begin(), operators.end());

    int max = operators.front().peopleCount;
    set<int> index;
    while (!operators.empty() && operators.front().peopleCount == max) {
        index.insert(operators.front().index);
        pop_heap(operators.begin(), operators.end());
        operators.pop_back();
    }

    while (!index.empty()) {
        cout << *index.begin() << " ";
        index.erase(index.begin());
    }


    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector<int> people[1000001];

int findGiftCount(int j) {
    if (people[j].empty()) {
        return 0;
    }

    int total = people[j].size();
    for (int i = 0; i < people[j].size(); i++) {
        total += findGiftCount(people[j][i]);
    }
    
    
    return total;
}


int main() {
    int n;
    cin >> n;
    int size = n;
    int parent, child;
    n--;
    while (n--) {
        cin >> parent >> child;
        people[parent].push_back(child);
    }
    for (int i = 0; i < size; i++) {
        cout << findGiftCount(i) << " ";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Demon {
    int attack;
    int security;
public:
    Demon(int attack = 0, int security = 0) {
        this->attack = attack;
        this->security = security;
    }
    int getAttack() const {
        return this->attack;
    }
    int getSecurity() const {
        return this->security;
    }

    bool operator<(const Demon& other) {
        return attack < other.attack&& security < other.security;
    }
};

bool sortByAttack(const Demon& a, const Demon& b) {
    return a.getAttack() < b.getAttack();
}

bool sortBySecurity(const Demon& a, const Demon& b) {
    return a.getSecurity() < b.getSecurity();
}


int findCount(vector<Demon>& demons) {
    vector<Demon> result;
    for (unsigned int i = 0; i < demons.size(); i++) {
        auto itterator = lower_bound(result.begin(), result.end(), demons[i]);
        if (itterator == result.end()) {
            result.push_back(demons[i]);
        }
        else {
            *itterator = demons[i];
        }
    }
    return result.size();
}

int main() {
    int n;
    cin >> n;
    int attack, security;
    vector<Demon> demons;
    for (int i = 0; i < n; i++) {
        cin >> security;
        cin >> attack;
        demons.push_back(Demon(security, attack));
    }
    stable_sort(demons.begin(), demons.end(),sortByAttack);
    int count_1 = findCount(demons);
    stable_sort(demons.begin(), demons.end(), sortBySecurity);
    int count_2 = findCount(demons);
    int count = max(count_1, count_2);
    cout << count << endl;

    return 0;
}
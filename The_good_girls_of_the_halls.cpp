#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool sortByEfficiency(const pair<pair<double, double>, unsigned int>& a, const pair<pair<double, double>, unsigned int>& b) {
    double ef1 = a.first.first*a.first.first / a.first.second;
    double ef2 = b.first.first*b.first.first / b.first.second;

    if (ef1 == ef2) {
        return a.first.first > b.first.first;
    }

    return  ef1 > ef2;
}

vector<pair<pair<double, double>, unsigned int>> saveIndex(const vector<pair<double, double>>& boysPairs) {
    vector<pair<pair<double, double>, unsigned int>> v;
    for (unsigned int i = 0; i < boysPairs.size(); i++) {
        v.push_back(make_pair(boysPairs[i], i + 1));
    }
    return v;
}

void printResult(const vector<pair<pair<double, double>, unsigned int>>& results) {
    for (unsigned int i = 0; i < results.size(); i++) {
        cout << results[i].second << " ";
    }
}

int main() {
    int n;
    cin >> n;
    pair<double, double> temp;
    vector<pair<double, double>> boysPairs;
    for (int i = 0; i < n; i++) {
        cin >> temp.first;
        cin >> temp.second;
        boysPairs.push_back(temp);
    }

    vector<pair<pair<double, double>, unsigned int>> indexWithPairs = saveIndex(boysPairs);
    stable_sort(indexWithPairs.begin(), indexWithPairs.end(), sortByEfficiency);
    printResult(indexWithPairs);

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



bool sortByPoint(const pair<pair<double, double>, unsigned int>& a, const pair<pair<double, double>, unsigned int>& b) {
    double point1 = (a.first.first * a.first.first) / a.first.second;
    double point2 = (b.first.first * b.first.first) / b.first.second;

    if (point1 == point2) {
        return a.first.first > b.first.first;
    }

    return  point1>point2;
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
    vector<pair<double, double>> teams;
    for (int i = 0; i < n; i++) {
        cin >> temp.first;
        cin >> temp.second;
        teams.push_back(temp);
    }
    vector<pair<pair<double, double>, unsigned int>> indexWithPairs = saveIndex(teams);
    stable_sort(indexWithPairs.begin(), indexWithPairs.end(), sortByPoint);
    printResult(indexWithPairs);
    return 0;
}

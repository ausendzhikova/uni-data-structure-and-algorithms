#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByFirst(const pair<int,unsigned int>& a, const pair<int,unsigned int>& b) {
    return a.first < b.first;
}

bool sortBySec(const pair<int, unsigned int>& a, const pair<int, unsigned int>& b) {
    return a.second < b.second;
}

vector<pair<int,unsigned int>> selectComplexity(vector<pair<int,unsigned int>>& teamExperiences, vector<int>& topicComplexity) {
    vector<pair<int,unsigned int>> selectedComplexities;

    for (unsigned int i = 0; i < teamExperiences.size(); i++) {
        auto temp = upper_bound(topicComplexity.begin(), topicComplexity.end(), teamExperiences[i].first);
        int index = temp - topicComplexity.begin()-1;
        if (index == -1) {
            index = 0;
        }else if (topicComplexity[index] != teamExperiences[i].first && index!=topicComplexity.size()-1) {
            int leftDiff = teamExperiences[i].first - topicComplexity[index];
            int rightDiff = topicComplexity[index + 1] - teamExperiences[i].first;
            if (leftDiff > rightDiff) {
                index += 1;
            }
        }
        selectedComplexities.push_back(make_pair(topicComplexity[index],teamExperiences[i].second));
    }

    return selectedComplexities;
}

vector<pair<int, unsigned int>> saveIndex(vector<int> teamExperineces) {
    vector<pair<int, unsigned int>> teamWithIndex;
    for (unsigned int i = 0; i < teamExperineces.size(); i++) {
        teamWithIndex.push_back(make_pair(teamExperineces[i], i));
    }
    return teamWithIndex;
}


void printResult(vector<pair<int,unsigned int>> results) {
    sort(results.begin(), results.end(), sortBySec);
    for (unsigned int i = 0; i < results.size(); i++) {
        cout << results[i].first << endl;
    }
}
int main() {
    unsigned int teamCount;
    unsigned int topicCount;
    cin >> topicCount;
    cin >> teamCount;
    int temp;
    vector<int> topicComplexity;
    for (unsigned int i = 0; i < topicCount; i++) {
        cin >> temp;
        topicComplexity.push_back(temp);
    }
    vector<int> teamExperiences;
    for (unsigned int i = 0; i < teamCount; i++) {
        cin >> temp;
        teamExperiences.push_back(temp);
    }
    vector<pair<int, unsigned int>> teamWithIndex = saveIndex(teamExperiences);
    sort(topicComplexity.begin(), topicComplexity.end());

    sort(teamWithIndex.begin(), teamWithIndex.end(),sortByFirst);
    printResult(selectComplexity(teamWithIndex, topicComplexity));


    return 0;
}


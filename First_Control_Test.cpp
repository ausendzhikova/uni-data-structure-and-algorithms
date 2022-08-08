#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;

vector<int> shortestDistance(string distributedVariants, char availableVariant) {
	vector<int> results;
	int len = distributedVariants.length();
	int prevDistance = INT_MAX;
	for (int i = 0; i < len; i++) {
		if (distributedVariants[i] == availableVariant) {
			prevDistance = i;
		}
		if (prevDistance == INT_MAX) {
			results.push_back(INT_MAX);
		}
		else {
			results.push_back(i - prevDistance);
		}
	}
	prevDistance = INT_MAX;
	for (int i = len - 1; i >= 0; i--) {
		if (distributedVariants[i] == availableVariant) {
			prevDistance = i;
		}
		if (prevDistance != INT_MAX) {
			results[i] = min(results[i], prevDistance - i);
		}
	}
	return results;
}

void printResult(vector<int> results) {
	for (auto res : results) {
		cout << res << " ";
	}
}
int main() {
	string str;
	cin >> str;
	char x;
	cin >> x;
	vector<int> result;
	result=shortestDistance(str, x);
	printResult(result);

	return 0;
}
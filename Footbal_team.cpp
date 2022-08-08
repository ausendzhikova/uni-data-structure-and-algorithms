#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int firstUnusedNum(vector<int> numbers) {
    int searchNum=1;
    sort(numbers.begin(), numbers.end());
    for (unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] > 0 && numbers[i] == searchNum) {
            searchNum++;
        }
    }
    return searchNum;
}

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    int input;
    for (int i = 0; i < n;i++) {
        cin >> input;
        arr.push_back(input);
    }
    int ans = firstUnusedNum(arr);
    cout << ans << endl;
    return 0;
}
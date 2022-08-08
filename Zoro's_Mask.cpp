#include <bits/stdc++.h>

using namespace std;
#define M 32

string convertDecToBin(int num) {
    bitset<M> binNum(num);
    string b = binNum.to_string();
    return b;
}

void findMask(set<string>& nums, int i) {
   
    for (auto x : nums) {
        if (x[i] == '1') {
            string temp = x;
            temp[i] = '0';
            nums.insert(temp);
        }
    }
}

set<string> createAVL(string binNum) {
    set<string> nums;
    nums.insert(binNum);
    int size = binNum.size();
    for (int i = 0; i < size; i++) {
        findMask(nums, i);
    }
    return nums;
}

int findUniqueMasks(vector<int> numbers) {
    int size = numbers.size();
    set<string> finalAVL;
    for (int i = 0; i < size; i++) {
        string binNum = convertDecToBin(numbers[i]);
        set<string> temp = createAVL(binNum);

        for (auto x : temp) {
            finalAVL.insert(x);
        }
    }

    return finalAVL.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    cout << findUniqueMasks(numbers) << endl;

    return 0;
}
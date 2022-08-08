#include <bits/stdc++.h>

using namespace std;

void findSmaller(vector<int>& nums,multimap<int, int>& sortNums, int k,vector<int>&small) {
    int size = nums.size();

    for (int i = size - 1; i >= 0; i--) {
        auto it = sortNums.lower_bound(nums[i]);
        vector<multimap<int, int>::iterator> numsToDelete;


        while (!sortNums.empty() && it!=sortNums.end() && it->first - nums[i] <= k) {
            if (it->first == nums[i]) {
                it++;
                continue;
            }
            small[it->second] = i;
            numsToDelete.push_back(it);
            it++;
        }

        for (auto x:numsToDelete) {
            sortNums.erase(x->first);
        }
        sortNums.insert({ nums[i],i });
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums;
    multimap<int, int> sortNums;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = -1;
    }
    findSmaller(nums, sortNums, k, small);

    for (int i = 0; i < n; i++) {
        cout << small[i] << " ";
    }

    return 0;
}

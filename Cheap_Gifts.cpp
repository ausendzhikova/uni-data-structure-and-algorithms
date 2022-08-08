#include <iostream>
#include <vector>

using namespace std;

void mergePrices(vector<int>& prices,const int left, const int middle, const int right) {
    //create a temp vector - v1 and v2
    vector<int> leftVec;
    vector<int> rightVec;
    const int leftLen = middle - left + 1;
    const int rightLen = right - middle;

    //copy data to temp vectors
    for (auto i = 0; i < leftLen; i++) {
        leftVec.push_back(prices[left + i]);
    }
    for (auto i = 0; i < rightLen; i++) {
        rightVec.push_back(prices[middle + 1 + i]);
    }
    
    auto leftIndex = 0, rightIndex = 0;
        unsigned mergedIndex = left;

    while (leftIndex < leftLen && rightIndex < rightLen) {
        if (leftVec[leftIndex] <= rightVec[rightIndex]) {
            prices[mergedIndex] = leftVec[leftIndex];
            leftIndex++;
        }
        else {
            prices[mergedIndex] = rightVec[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    //if there are any remaining elemnts in  leftVec, copy them
    while (leftIndex < leftLen) {
        prices[mergedIndex] = leftVec[leftIndex];
        mergedIndex++;
        leftIndex++;
    }

    //if there are any remaining elemnt in rightVec, copy them
    while (rightIndex < rightLen) {
        prices[mergedIndex] = rightVec[rightIndex];
        mergedIndex++;
        rightIndex++;
    }



}

void mergeSortPrices(vector<int>& prices, const int left, const int right) {
    int middle;
    if (left >= right) {
        return;
    }
        middle = (left + right) / 2;
        mergeSortPrices(prices, left, middle);
        mergeSortPrices(prices, middle + 1, right);
        mergePrices(prices, left, middle, right);
    
}

long int minSum(vector<int>& prices, int k) {
    long int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += prices[i];
    }
    return sum;
}

int main() {
    int N;
    cin >> N;
    vector<int> prices;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        prices.push_back(input);
    }
    int k;
    cin >> k;
    mergeSortPrices(prices, 0, prices.size()-1);
    cout << minSum(prices, k) << endl;
    return 0;
}
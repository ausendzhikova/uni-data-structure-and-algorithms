#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& numbers, const int left, const int middle, const int right) {
 
    vector<int> leftVec;
    vector<int> rightVec;
    const int leftLen = middle - left + 1;
    const int rightLen = right - middle;

    
    for (auto i = 0; i < leftLen; i++) {
        leftVec.push_back(numbers[left + i]);
    }
    for (auto i = 0; i < rightLen; i++) {
        rightVec.push_back(numbers[middle + 1 + i]);
    }

    auto leftIndex = 0, rightIndex = 0;
    unsigned mergedIndex = left;

    while (leftIndex < leftLen && rightIndex < rightLen) {
        if (leftVec[leftIndex] <= rightVec[rightIndex]) {
            numbers[mergedIndex] = leftVec[leftIndex];
            leftIndex++;
        }
        else {
            numbers[mergedIndex] = rightVec[rightIndex];
            rightIndex++;
        }
        mergedIndex++;
    }

    while (leftIndex < leftLen) {
        numbers[mergedIndex] = leftVec[leftIndex];
        mergedIndex++;
        leftIndex++;
    }

    while (rightIndex < rightLen) {
        numbers[mergedIndex] = rightVec[rightIndex];
        mergedIndex++;
        rightIndex++;
    }



}


void mergeSort(vector<int>& numbers, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(numbers, left, mid);
    mergeSort(numbers, mid + 1, right);
    merge(numbers, left, mid, right);
}

vector<int> removeRepeatElements(vector<int> numbers) {
    vector<int> v;
    if (numbers.size() == 0 || numbers.size() == 1) {
        return numbers;
    }
    
    for (unsigned int i = 0; i < numbers.size()-1; i++) {
        if (numbers[i] != numbers[i + 1]) {
            v.push_back(numbers[i]);
        }
    }
    v.push_back(numbers[numbers.size() - 1]);

    return v;
}

void printResult(vector<int> numbers) {
    for (unsigned int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        numbers.push_back(temp);
    }
    mergeSort(numbers,0,numbers.size()-1);
    
    printResult(removeRepeatElements(numbers));

    return 0;
}

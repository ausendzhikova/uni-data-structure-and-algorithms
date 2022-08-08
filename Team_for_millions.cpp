#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> convertCharToInt(string& str) {
    vector<int> numbers;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            numbers.push_back(str[i] - 28);
        }
        else if (str[i] >= 97 && str[i] <= 122) {
            numbers.push_back(str[i] - 86);
        }
        else {
            numbers.push_back(str[i] - '0');
        }
    }
    return numbers;
}

string convertIntToChar(vector<int>& num) {
    string str;
    for (unsigned int i = 0; i < num.size(); i++) {
        if (num[i] >= 11 && num[i] <= 36) {
            str.push_back(num[i] + 86);
        }
        else if (num[i] >= 37 && num[i] <= 62) {
            str.push_back(num[i] + 28);
        }
        else {
            str.push_back(num[i] + '0');
        }
    }
    return str;
}


int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;
    vector<int> num;
    num = convertCharToInt(str);
    sort(num.begin(), num.end());
    cout << convertIntToChar(num) << endl;

    return 0;
}
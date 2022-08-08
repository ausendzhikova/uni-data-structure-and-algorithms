#include <iostream>
#include <string>
using namespace std;

int symbolsRepeat(string word, char symbol,int n) {
    unsigned int wholeWordCount = n / word.size();
    unsigned int otherCharCount = n % word.size();
    unsigned int count = 0;

    for (unsigned int i = 0; i < word.size(); i++) {
        if (word[i] == symbol) {
            count++;
        }
    }

    count *= wholeWordCount;

    for (unsigned int i = 0; i < otherCharCount; i++) {
        if (word[i] == symbol) {
            count++;
        }
    }

    return count;
}

int main() {
    string str;
    cin >> str;
    int n;
    cin >> n;
    char symbol;
    cin >> symbol;
    int count = symbolsRepeat(str, symbol,n);
    cout << count<< endl;

    return 0;
}
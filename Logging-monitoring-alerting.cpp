#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Timestamp {
private:
    int hour;
    int min;
    int sec;
    int day;
    int month;
    int year;

public:
    Timestamp(int hour = 0, int min = 0, int sec = 0, int day = 0, int month = 0, int year = 0) {
        this->hour = hour;
        this->min = min;
        this->sec = sec;
        this->day = day;
        this->month = month;
        this->year = year;
    }


    bool operator<(const Timestamp& other) const {
        if (this->year < other.year) {
            return true;
        }
        if (this->year == other.year) {
            if (this->month < other.month) {
                return true;
            }
            if (this->month == other.month) {
                if (this->day < other.day) {
                    return true;
                }
                if (this->day == other.day) {
                    int seconds = this->hour * 3600 + this->min * 60 + this->sec;
                    int otherSec = other.hour * 3600 + other.min * 60 + other.sec;
                    if (seconds < otherSec) {
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
};

void printResult(vector<int> index){
     
    for (unsigned int i = 0; i < index.size(); i++) {
        cout << ++index[i] << endl;
    }
}


int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<Timestamp> timestamps;
    for (int i = 0; i < n; i++) {
        string hours, min, sec, day, month, year;
        getline(cin, hours, ':');
        getline(cin, min, ':');
        getline(cin, sec, ' ');
        getline(cin, day, '.');
        getline(cin, month, '.');
        getline(cin, year);
        Timestamp tms = Timestamp(stoi(hours), stoi(min), stoi(sec), stoi(day), stoi(month), stoi(year));
        timestamps.push_back(tms);
    }
    
    vector<int> index(timestamps.size(), 0);
    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    stable_sort(index.begin(), index.end(), 
        [&](const int& first, const int& second) {
        return timestamps[first] < timestamps[second];
        }
    );
    
    printResult(index);
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class WeirdQueries {
private:
    double P;
    double S;
    int index;
public:
    WeirdQueries(double P = 0, double S = 0) {
        this->P = P;
        this->S = S;
    }
    void calculateIndex(const vector<double>& numbers) {
        this->index = upper_bound(numbers.begin(), numbers.end(), P) - numbers.begin() - 1;
    }

    int calculateCount(const vector<double>& sumsOfElements, const vector<double>& numbers) {
        calculateIndex(numbers);
        int i = numbers.size() - index-1;
        double sum = S;
        if (S < numbers[index]) {
            return 0;
        }
        
        if (i != 0) {
            sum += sumsOfElements[i - 1];
        }
        if (sumsOfElements[sumsOfElements.size() - 1] <=  sum) {
            return index + 1;
        }


        int it = (upper_bound(sumsOfElements.begin() + i, sumsOfElements.end(), sum)) - (sumsOfElements.begin() + i) - 1;
        return it + 1;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<double> numbers;
    for (int i = 0; i < n; i++) {
        double temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    stable_sort(numbers.begin(), numbers.end());

    vector<WeirdQueries> wq;
    for (int i = 0; i < q; i++) {
        double p, s;
        cin >> s >> p;
        wq.push_back(WeirdQueries(p, s));
    }

    
    vector<double> sums;
    double temp = 0;

    for (int i = numbers.size() - 1; i >= 0; i--) {
        temp += numbers[i];
        sums.push_back(temp);
    }

    for (unsigned int i = 0; i < wq.size(); i++) {

        printf("%i \n", wq[i].calculateCount(sums, numbers));
    }

    return 0;
}
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    unordered_map<long long,long long> animals;
    unordered_map<long long, long long> availableAnimals;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        long long an;
        cin >> an;
        if (an % k == 0) {
            if (availableAnimals.count(an / k)) {
                count += availableAnimals[an / k];
            }

            if (animals.count(an / k)) {
                availableAnimals[an]+=animals[an/k];
            }
        }
        animals[an]++;
    }
    

    printf("%lld\n",count);
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> results(n);
    vector<string> input;
    map<string,int> m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        m[str]++;
        input.push_back(str);
    }
    for(int i=0;i<n;i++){
        results[i]=m[input[i]];
    }
    
    for(int i=0;i<n;i++){
        cout<<results[i]<<" ";
    }
    return 0;
}
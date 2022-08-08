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
    map<int,int> m;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        m[num]++;
    }
    
    int sum=0;
    for(auto x: m){
        if(x.second%2!=0){
            sum+=(x.first*x.second);
        }
    }
    
    printf("%d\n",sum);
    return 0;
}

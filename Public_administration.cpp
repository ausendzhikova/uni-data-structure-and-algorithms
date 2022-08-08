#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    unordered_map<int,int> nums;
    map<int,int> orderNums;
    vector<int> numbers;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(!nums.count(num)){
            orderNums.insert({i,num});
        }
        nums[num]++;
    }
    
    vector<int> repeat;
    vector<int> nonRepeat;
    
    for(auto x: orderNums){
        if(nums[x.second]>1){
            repeat.push_back(x.second);
        }else{
            nonRepeat.push_back(x.second);
        }
        
    }
    
    for(int i=0;i<nonRepeat.size();i++){
        cout<<nonRepeat[i]<<" ";
    }
    
    for(int i=0;i<repeat.size();i++){
        cout<<repeat[i]<<" ";
    }
    return 0;
}

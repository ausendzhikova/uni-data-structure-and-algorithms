#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

struct Queries{
    int submitTime;
    int needTime;
    
    Queries(int submitTime=0,int needTime=0){
        this->submitTime=submitTime;
        this->needTime=needTime;
    }
    
    bool operator>(const Queries&  other) const{
        return this->needTime>other.needTime;
    }
};

int main() {
    int queriesCount;
    cin>>queriesCount;
    vector<Queries> queries;
    
    for(int i=0;i<queriesCount;i++){
        int needTime;
        cin>>needTime;
        queries.push_back(Queries(i,needTime));
    }
    
    priority_queue<Queries,vector<Queries>,greater<Queries>> pq;
    int start=0;
    int minTime=INT_MAX;
    int maxTime=INT_MIN;
    int i=0;
    while(i<queriesCount || !pq.empty()){
        
        while(i<queriesCount && queries[i].submitTime<=start){
            pq.push(queries[i]);
            ++i;
        }
        Queries cur=pq.top();
        pq.pop();
        int ttime=start-cur.submitTime+cur.needTime;
        minTime=min(minTime,ttime);
        maxTime=max(maxTime,ttime);
        start+=cur.needTime;
    }
    
    printf("%d %d\n",minTime,maxTime);
    return 0;
}

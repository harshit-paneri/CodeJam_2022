#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<int> F;
vector<int> P;

void get_input(){
    scanf("%d", &N);
    F.resize(N+1);
    F[0] = 0;
    for(int i=1; i<=N; ++i)
        scanf("%d", &F[i]);
    P.resize(N+1);
    P[0] = 0;
    for(int i=1; i<=N; ++i)
        scanf("%d", &P[i]);
}

void solve(){
    vector<bool> has_child(N+1,false);
    vector<bool> visited(N+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minq;
    long long answer = 0;

    for(int i=1; i<=N; ++i)
        has_child[P[i]] = true;

    for(int i=1; i<=N; ++i){
        if(!has_child[i]){
            minq.push(make_pair(F[i],i));
            visited[i] = true;
        }
    }
    while(!minq.empty()){
        auto p = minq.top(); minq.pop();
        int max_val = p.first;
        int idx = p.second;

        if(visited[P[idx]]){
            //printf("idx:%d max_val:%d\n",idx,max_val);
            answer += max_val;
        }
        else{
            visited[P[idx]] = true;
            minq.push(make_pair(max(max_val,F[P[idx]]),P[idx]));
        }
    }

    printf("%lld\n", answer);
}


int main(int argc, char** argv){
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; ++i){
        printf("Case #%d: ",i+1);
        get_input();
        solve();
    }
}
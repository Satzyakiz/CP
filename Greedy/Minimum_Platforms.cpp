// Given arrival and departure times of all trains that reach a railway station. 
// Your task is to find the minimum number of platforms required for the railway
// station so that no train waits.
//
// Note: Consider that all the trains arrive on the same day and leave on
// the same day. Also, arrival and departure times will not be same for a
// train, but we can have arrival time of one train equal to departure of
// the other. In such cases, we need different platforms, i.e at any given
// instance of time, same platform can not be used for both departure of a
// train and arrival of another.
//
// Example:
// Input:
// 2
// 6
// 0900  0940 0950  1100 1500 1800
// 0910 1200 1120 1130 1900 2000
// 3
// 0900 1100 1235
// 1000 1200 1240
//
// Output:
// 3
// 1

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    vector<int> arrival(n), dept(n);
    vector<bool> visited(n);
    vector<pair<int,int>> schedule(n);
    for(int i=0; i<n; i++) cin>>arrival[i];
    for(int i=0; i<n; i++) cin>>dept[i];
    for(int i=0; i<n; i++){
        int x = arrival[i], y = dept[i];
        if(y < x) y += 2400;
        schedule[i] = {x,y};
    }

    sort(schedule.begin(), schedule.end());
    int ans = 0;
    while(1){
        int i=0, flag = 0,end;
        for(i=0; i<n; i++){
            if(!visited[i]){
                end = schedule[i].second;
                visited[i] = true;
                flag = 1;
                break;
            }
        }
        for( ; i<n; i++){
            if(!visited[i] && schedule[i].first > end){
                visited[i] = true;
                end = schedule[i].second;
            }
        }

        if(!flag) break;
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

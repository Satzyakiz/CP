#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

void helper(int start,int prod,int target,vector<int> &curr,vector<vector<int>> &res){
    if(start > target || prod > target)
        return;
    if(prod == target){
        res.emplace_back(curr);
        return;
    }

    for(int i=start; i<=target; i++){
        if(i * prod > target)
            break;
        if(target % i == 0){
            curr.emplace_back(i);
            helper(i,i*prod,target,curr,res);
            curr.pop_back();
        }
    }
}

vector<vector<int>> solver(int x){
    vector<vector<int>> res;
    vector<int> currRes;
    helper(2,1,x,currRes,res);
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> result = solver(n);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

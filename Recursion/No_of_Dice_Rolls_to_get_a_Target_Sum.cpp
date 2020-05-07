// IP: 2 6 7
// OP: 6
// DP SOLUTION IN DP folder
#include<bits/stdc++.h>
using namespace std;

int rollsReq(int d,int f,int target){
    if(d == 0 && target == 0) return 1;
    if(d == 1 && (target>=1 && target<=f))
        return 1;
    else if(d == 1 && target > f)
        return 0;
    int count = 0;
    for(int i=1; i<=f; i++){
        count += rollsReq(d-1,f,target-i);
    }
    return count;

}

int main(){
    int d,f,target;
    cin>>d>>f>>target;
    cout<<rollsReq(d,f,target)<<endl;
    return 0;
}

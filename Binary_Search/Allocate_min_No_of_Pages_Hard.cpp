// You are given N number of books. Every ith book has Pi number of pages.
// You have to allocate books to M number of students. There can be many
// ways or permutations to do so. In each permutation one of the M students
// will be allocated the maximum number of pages. Out of all these permutations,
// the task is to find that particular permutation in which the maximum number
// of pages allocated to a student is minimum of those in all the other
// permutations, and print this minimum value.
// Each book will be allocated to exactly one student. Each student has to
// be allocated atleast one book.
// Note: Return -1 if a valid assignment is not possible, and allotment
// should be in contiguous order.
// Input:
// 2
// 4
// 12 34 67 90
// 2
// 3
// 15 17 20
// 2
// Output:
// 113
// 32
//
// Explaination:
// Testcase 1:Allocation can be done in following ways:
// {12} and {34, 67, 90}     Maximum Pages = 191
// {12, 34} and {67, 90}     Maximum Pages = 157
// {12, 34, 67} and {90}        Maximum Pages = 113
//
// Therefore, the minimum of these cases is 113, which is selected as output.
//
// Testcase 2: Allocation can be done in following ways:
// {15} and {17, 20} Maximum pages = 37
// {15, 17} and {20} Maximum Pages = 32
//
// So, the output will be 32.
//
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool isPossible(vector<int> &arr,ll mid,int p){
    int count = 1;
    ll sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > mid)
            return false;
        if(sum + arr[i] > mid){
            count++;
            sum = arr[i];
            if(count > p)
                return false;
        }else{
            sum += arr[i];
        }
    }
    return true;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int p;
    cin>>p;
    if(n < p){
        cout<<"-1\n";
        return;
    }
    ll sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    ll low = 0, high = sum;
    ll ans = INT_MAX;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(isPossible(arr,mid,p)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if(ans >= INT_MAX)
        cout<<"-1\n";
    else
        cout<<ans<<endl;;

}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}


//Interviewbit

#define ll long long

bool isPossible(vector<int> &arr,int pages,int people){
    int count = 1, sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > pages)
            return false;
        if(sum + arr[i] > pages){
            count++;
            sum = arr[i];
            if(count > people)
                return false;
        }else{
            sum += arr[i];
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size() < B)
        return -1;
    ll low = 0,high;
    for(int &x: A) high += x;
    ll ans = -1;
    while(low <= high){
        ll mid = low + (high - low)/2;
        if(isPossible(A,mid,B)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }

    return ans;
}

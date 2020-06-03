// You are given an array A of size N. Your task is to find the
// minimum number of operations needed to convert the given array to
// 'Palindromic Array'.
// Palindromic Array:
// [23,15,23] is a ‘Palindromic Array’ but [2,0,1] is not.
// The only allowed operation is that you can merge two adjacent
// elements in the array and replace them with their sum.
//
// Input:
// The first line of input contains an integer T denoting the number
// of test cases.The first line of each test case is N, where N is
// the size of array.The second line of each test case contains N
// space separated integers which is the input for the array.
//
// Output:
// Output the minimum number of operations required to make the given
// array a palindromic array.
//
// Constraints:
// 1 <= T <= 100
// 1 <= N <= 100
// 1 <= A[] <= 100
//
// Example:
// Input:
// 2
// 5
// 3 2 3 3 5
// 4
// 5 3 3 4
// Output:
// 1
// 3
//
// Explanation:
// For Test Case 1: [3 2 3 3 5] after merging the 1st two elements
// 3 and 2, we get the array as [5 3 3 5] which is a palindrome,
// hence only 1 operation is needed.

//Source : GFG

#include <bits/stdc++.h>
using namespace std;
bool pal(deque<int> dq){
    int i=0,n=dq.size()-1;
    while(i<n){
        if(dq[i] != dq[n])
            return false;
        i++;
        n--;
    }
    return true;
}
void solve(){
    int n,x;
    cin>>n;
    deque<int> dq;
    for(int i=0; i<n;i++){
        cin>>x;
        dq.push_back(x);
    }
    int ways = 0;
    while(dq.size() > 1){
        if(pal(dq)){
            cout<<ways<<endl;
            return;
        }
        if(dq.front() == dq.back()){
            dq.pop_front();
            dq.pop_back();
        }
        else if(dq.front() < dq.back()){
            int temp = dq.front();
            dq.pop_front();
            dq[0] = dq.front() + temp;
            ways++;
        }else{
            int temp = dq.back();
            dq.pop_back();
            temp += dq.back();
            dq.pop_back();
            dq.push_back(temp);
            ways++;
        }

    }
    cout<<ways<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}

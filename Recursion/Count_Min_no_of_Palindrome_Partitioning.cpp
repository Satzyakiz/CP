// IP: "nitin" OP: 0
// IP: "abcbd" OP: 2 ['a','bcb','d']
// {3 elements can be made by 2 partitions}
//
// IP:
// 4
// abcba
// abc
// ababcb
// aabbcc
// OP:
// 0
// 2
// 1
// 2


#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
  while(i<j){
    if(s[i++] != s[j--]) return false;
    // i++;j--;
  }
  return true;
}

int getMinPartitions(string s,int i,int j){
  if(i >= j) return 0; //if i==j, then sting is of size 1,and a letter is always a palindrome
  if(isPalindrome(s,i,j)) return 0;
  int minPartitions = INT_MAX;
  for(int k=i; k<j; k++){
    //Length is made variable until 0 is returned.
    int temp = getMinPartitions(s,i,k)+getMinPartitions(s,k+1,j)+1;
    //1 is added because while calculating from i to k and k+1 to j
    //we already made a partition.
    minPartitions = min(minPartitions,temp);
  }
  return minPartitions;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin.ignore();
    cin>>s;
    cout<<getMinPartitions(s,0,s.size()-1)<<endl;
  }
  return 0;
}

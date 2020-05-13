// The count-and-say sequence is the sequence of integers beginning as follows:
//
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as one 1 or 11.
// 11 is read off as two 1s or 21.
//
// 21 is read off as one 2, then one 1 or 1211.
//
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//
// Example:
//
// if n = 2,
// the sequence is 11.
  // if n = 5, seq : 111221

#include<bits/stdc++.h>
using namespace std;
string getResult(int A){
  if(A == 1) return "1";
  string a="1", b="";
  int count = 1;
  for(int i=1; i<A; i++){ //already one item is there in a, so loop is traversed n-1 times
    int j=0;
    while(1){
      if(a[j+1] == a[j]) count++;
      else{
        b+= to_string(count);
        b+= a[j];
        count = 1;
        if(a[j+1] == NULL){
          a = b;
          b="";
          break;
        }
      }
      j++;
    }
  }
  return a;
}
int main(){
  int A;
  cin>>A;
  cout<<getResult(A)<<endl;
}

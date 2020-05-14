// Scramble String using Recursion
// Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
// Below is one possible representation of A = “great”:
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children.
//
// For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.
//
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that “rgeat” is a scrambled string of “great”.
//
// Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.
//
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that “rgtae” is a scrambled string of “great”.
// IP:
// abcde
// ceabd
// OP:
// False

#include<bitss/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2){
  if(s1.size() != s2.size()) return false;
  if(s1 == s2) return true;
  if(s1.length() <= 1) return false;
  bool res = false;
  int n = s2.size();
  for(int i=1; i<n; i++){ //MCM format
    //Either the values are swapped
    //like gr eat to rg eat
    bool swap = isScramble(s1.substr(0,i),s2.substr(n-i,i)) == true
              && isScramble(s1.substr(i,n-i),s2.substr(0,n-i)) == true;
    //Or values are not swapped
    bool noswap = isScramble(s1.substr(0,i),s2.substr(0,i)) == true
              && isScramble(s1.substr(i,n-i),s2.substr(i,n-i)) == true;
    if(swap || noswap){
      return true;
    }
  }
  return false;
}

int main(){
  string s1,s2;
  cin>>s1;
  cin.ignore();
  cin>>s2;

  if(isScramble(s1,s2)){
    cout<<"True";
  }
  else{
    cout<<"False";
  }
  return 0;
}

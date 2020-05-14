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

//Extension of recursive approach, using map

#include<bits/stdc++.h>
using namespace std;

unordered_map<string,bool> um;
bool isScramble(string a, string b) {
          if(a.size() != b.size()) return false;
          if(a == b) return true;
          string newStr = a+"_"+b;
          if(um.find(newStr) != um.end()) return um[newStr]; //If value already present in map
          int n = a.size();
          bool res = false;
          for(int i=1; i<n; i++){
            bool swap = isScramble(a.substr(0,i),b.substr(n-i,i)) == true
                && isScramble(a.substr(i,n-i),b.substr(0,n-i)) == true;
            bool noswap = isScramble(a.substr(0,i),b.substr(0,i)) == true
                && isScramble(a.substr(i,n-i),b.substr(i,n-i)) == true;
            if(swap || noswap){
              res = true;
              break;
            }
          }
          um[newStr] = res;
          return res;
        }

int main(){
  string a,b;
  cin>>a;
  cin.ignore();
  cin>>b;
  if(isScramble(a,b)){
    cout<<"True";
  }
  else{
    cout<<"False";
  }
  return 0;
}

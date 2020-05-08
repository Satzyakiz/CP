//
// Given a string containing just the characters '(' and ')',
// find the length of the longest valid (well-formed) parentheses substring.
// IP: "()(())"
// OP: 6
// IP: "()(()"
// OP: 2

#include<bits/stdc++.h>
using namespace std;

int countLength(string s){
  stack<int> stk;
  int count = 0;
  for(int i=0; i<s.size(); i++){
    if(!stk.empty() && s[stk.top()] == '(' && s[i] == ')'){
        stk.pop();
      if(stk.empty()){ // If stack is currentlu empty, it means all the characters till now
        //form a perfect set of paranthesis, so we count from 0 to i as length
        //which is nothing but i+1
        count = max(count, i+1);
      }
      else{
        //if stack is not empty, it means that perfect mathching is from the index next
        //to the top-most element of the stack till i.
        count = max(count,i-stk.top());
      }
    }
    else{
      stk.push(i); //Push the current index of the character if there is no matching
    }
  }
  return count;
}

int main(){
  string s;
  cin>>s;

  cout<<countLength(s)<<endl;
  return 0;
}
int main(){
  string s;
  cin>>s;
  cout<<countLength(s)<<endl;
  return 0;
}

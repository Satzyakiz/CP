
//Using iterative approach
#include<bits/stdc++.h>
using namespace std;
int tribonacci(int n){
  int a= 0, b = 1, c = 1;
  if(n == 0) return a;
  if(n == 1|| n == 2) return b;
  int ans = 0;
  for(int i=3; i<=n; i++){
      ans = a+b+c;
      a = b;
      b = c;
      c = ans;
  }
  return ans;
}

int main(){
  int n;
  cin>>n;
  cout<<tribonacci(n)<<endl;
  return 0;
}

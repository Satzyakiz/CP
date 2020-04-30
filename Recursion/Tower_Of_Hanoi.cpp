#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char From, char To, char Aux){
  if(n == 1){
    cout<<"Move disk 1 from tower "<<From<<" to tower "<<To<<endl;
    return;
  }
  TowerOfHanoi(n-1,From,Aux,To);
  cout<<"Move disk "<<n<<" from tower "<<From<<" to tower "<<To<<endl;
  TowerOfHanoi(n-1,Aux,To,From);
}

int main(){
  int n;
  cin>>n;
  TowerOfHanoi(n,'A','C','B');
  return 0;
}

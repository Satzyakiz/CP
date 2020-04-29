//Min Heap Implementation using priority queue.

#include<bits/stdc++.h>
using namespace std;

int main(){
  priority_queue <int, vector<int>, greater<int>> pq;
  pq.push(10);
  pq.push(8);
  pq.push(6);
  pq.push(4);
  pq.push(-2);

  cout<<"Top Element : "<<pq.top()<<endl;

  cout<<"Elements of the min heap : \n";
  while( !pq.empty()){
    cout<<pq.top()<<"  ";
    pq.pop();
  }
  cout<<endl;
  
  return 0;
}

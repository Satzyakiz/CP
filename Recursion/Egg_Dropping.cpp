
//Recursive Approach of egg dropping problem

#include<bits/stdc++.h>
using namespace std;
int eggDrop(int eggs,int floors){
  if(floors == 0 || floors == 1) return floors;
  if(eggs == 1) return floors;

  int minVal = INT_MAX;
  for(int k=1; k<=floors; k++){
    //k denotes current floor
    //1 is added for current drop
    int temp = 1+max(eggDrop(eggs-1,k-1),eggDrop(eggs,floors-k)); //Get the maximum worst case
    //eggDrop(eggs-1,k-1): This indicates that egg is broken
    // after dropping current floor
    //eggDrop(eggs,floors-k): This indicates that egg is not broken
    // after dropping current floor, so no of eggs don't change
    minVal = min(minVal,temp);
  }
  return minVal;
}

int main(){
  int eggs,floors;
  cin>>eggs>>floors;
  cout<<eggDrop(eggs,floors)<<endl;
  return 0;
}



int getSum(vector<int> arr,int k){
  sort(A.begin(),A.end());
  while(k--){
    if(A[i] == 0) break;//All the negetions could be done in it
    //and it would not affect the total sum
    else if(A[i] < 0){
      A[i] *= -1;
      sort(A.begin(),A.end()); //So that the least element becomes the first element.
    }
    else{
      A[i] *= -1;
    }
  }
  int total = 0;
  for(int x: arr) total += x;
  return total;
}

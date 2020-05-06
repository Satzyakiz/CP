
// Find LCM of a set of nos

//a is greater than b
int gcd(int a,int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}
int LCM(vector<int> arr){
  int ans = 1;
  for(int i=0; i<arr.size(); i++){
    ans = (ans*arr[i])/(gcd(ans,arr[i]));
  }

  return ans;
}

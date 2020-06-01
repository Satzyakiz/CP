//Exponentitaion take linear time to be computed. O(n)
//Fast Exponentitaion takes O(logn) time

// Compute (a^b)%c

//Recursive
int power(int a,int b,int c){
  if(a == 0) return 0;
  if(b == 0) return 1;
  // if(b == 1) return a%c;
  int ans = power(a,b/2,c);
  ans = ans%c * ans%c;
  if(b & 1)
    ans = ans * a%c;
  return ans;
}
//Iterative
int power(int a,int b,int c){
  if(a == 0) return 0;
  if(b == 0) return 1;
  // if(b == 1) return a%c;
  int ans = 1;
  a = a%c;
  while(b){
    if(b & 1) ans = ans * a%c;
    b = b >> 1;
    a = a%c * a%c;
  }
  return ans;
}

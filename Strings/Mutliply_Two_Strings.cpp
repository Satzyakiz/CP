//Basic rules of Multiplication
//12 * 10:
//     0 0
// + 1 2
// ----------
//   1 2 0

string multiply(string A, string B){
  int l1 = A.size(), l2 = B.size();
  string ans(l1+l2,'0'); //Fill the string with 0
  for(int i=l1-1; i>=0; i--){
    for(int j=l2-1; j>=0; j--){
      int temp = (A[i]-'0')*(B[j]-'0') + (ans[i+j+1] - '0');
      ans[i+j+1] = temp % 10 + '0'; //To convert into character
      ans[i+j] = temp/10;
    }
  }
  for(int i=0; i<l1+l2; i++){
    if(ans[i] != '0') // To avoid leading zeroes
      return ans.substr(i);
  }
  return "0";
}

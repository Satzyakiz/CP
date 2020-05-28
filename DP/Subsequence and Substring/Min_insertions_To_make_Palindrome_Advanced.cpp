// Given an string A. The only operation allowed is to insert
// characters in the beginning of the string.(Very Important)
//
// Find how many minimum characters are needed to be inserted to make
// the string a palindrome string.

int minInsertionsAtBeginning(string A){
  string B = A;
  reverse(B.begin(),B.end());
  if(A == B) return 0;
  string temp;
  int n = A.size();
  for(int i=n-1; i>=0; i--){
    temp += A[i];
    string x = temp + A;
    string y = x;
    reverse(y.begin(),y.end());
    if(x == y)
      return temp.size();
  }
  return 0; // Irrelevant
}

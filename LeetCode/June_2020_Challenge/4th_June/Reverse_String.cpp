


void reverse(vector<char> s){
  int i=0,n=s.size()-1;
  while(i < n){
    swap(s[i],s[n]);
    i++,n--;
  }
}

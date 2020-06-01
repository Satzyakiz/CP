// Compare two version numbers version1 and version2.
//
// If version1 > version2 return 1,
// If version1 < version2 return -1,
// otherwise return 0.
//
// Here is an example of version numbers ordering:
//
// 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

string getNext(string s, int &i){
  while(i<s.size() && s[i] == '0')
    i++;
  string res;
  while(i<s.size() && s[i] != '.'){
    res += s[i++];
  }
  i++;
  return res;
}

int compare(string a,string b){
  if(a == b) return 0;
  if(a.size() == b.size())
    return (a < b) ? -1 : 1;
  return (a.size() < b.size()) ? -1 : 1;
}


int Solution::compareVersion(string v1, string v2)
{
    if(v1 == v2) return 0;
  int i=0,j=0;
  while(i<v1.size() || j<v2.size()){
    int c = compare(getNext(v1,i),getNext(v2,j));
    if(c != 0)
      return c;
  }
  return 0;
}

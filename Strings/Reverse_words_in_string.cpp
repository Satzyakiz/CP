// I/P: "The sky is blue"
// O/P: "blue is sky The"
//Python Solution
def reverseWords(s):
    words = s.split(' ')
    words = reversed(words)
    return (' ').join(words)
    
// C++ Solution:
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0,start;
        string ans="",temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(temp.size() == 0){
                    continue;
                }
                else{
                    reverse(temp.begin(),temp.end());
                    if(ans.size() != 0)
                        ans+= " "+temp;
                    else
                        ans += temp;
                    temp = "";
                }
            }
            else{
                temp += s[i];
            }
        }
        if(temp.size() != 0){
            reverse(temp.begin(),temp.end());
            if(ans.size() != 0){
                ans += " "+temp;
            }
            else{
                return temp;
            }
        }
        return ans;
}
int main(){
  string s;
  cin>>s;
  cout<<reverseWords(s)<<endl;
  return 0;
}

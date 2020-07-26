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
      ans[i+j] += temp/10;
    }
  }
  for(int i=0; i<l1+l2; i++){
    if(ans[i] != '0') // To avoid leading zeroes
      return ans.substr(i);
  }
  return "0";
}

//Binary Multiplication
#include<bits/stdc++.h>
using namespace std;


void solve(){
    string s1, s2;
    cin>>s1>>s2;
    int l1 = s1.size(), l2 = s2.size();
    vector<int> arr(l1+l2);
    for(int i=l1-1; i>=0; i--){
        for(int j=l2-1; j >= 0; j--){
            // cout<<s1[i]<<" "<<s2[j]<<endl;
            arr[i+j+1] = (s1[i] - '0') * (s2[j] - '0') + arr[i+j+1];
            arr[i+j] += arr[i+j+1] / 2;
            arr[i+j+1] %= 2;
        }
    }
    // for(int &x: arr)
    //     cout<<x<<" ";
    // cout<<endl;
    int ans = 0;
    for(int i=l1+l2-1; i>=0; i--){
        if(arr[i]){
            ans += pow(2,l1+l2-1-i);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

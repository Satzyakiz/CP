// Given two strings. Find the smallest window in the first string 
// consisting of all the characters of the second string.
//
// Input:
// 2
// timetopractice
// toc
// zoomlazapzo
// oza
//
// Output:
// toprac
// apzo


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow (string S, string P){
    // Your code here
    int pSize = P.size(), sSize = S.size();

    if(pSize > sSize){
        return "-1";
    }

    vector<int> Smap(26,0), Pmap(26,0);

    for(char &c: P){
        Pmap[c - 'a']++;
    }

    int size=INT_MAX,sIn=-1;
    int start = 0,end = 0, count=0;

    for(int j=0; j<sSize; j++){
        Smap[S[j]-'a']++;
        if(Smap[S[j]-'a'] <= Pmap[S[j]-'a']){
            count++;
        }

        if(count == pSize){

            while(Smap[S[start]-'a'] > Pmap[S[start]-'a']){
                Smap[S[start]-'a']--;
                start++;
            }

            int window_size = j - start + 1;

            if(window_size < size){
                size = window_size;
                sIn = start;
            }
        }

    }
    if(sIn == -1){
        return "-1";

    }
    return S.substr(sIn,size);

}

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;

        cout<<smallestWindow(s, pat)<<endl;

    }
	return 0;
}  // } Driver Code Ends

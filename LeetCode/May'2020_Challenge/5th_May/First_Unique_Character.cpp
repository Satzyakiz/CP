
// Given a string, find the first non-repeating character 
// in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.


int firstUniqChar(string s) {
        if(s.size() == 0) return -1;
        if(s.size() == 1) return 0;
        unordered_map<char,pair<int,int>> um;
        for(int i=0; i<s.size(); i++){
            if(um.find(s[i]) != um.end()){
                um[s[i]].first += 1;
            }
            else{
                um[s[i]] = {1,i};
            }
        }
        int ans = -1;
        for(auto i=um.begin(); i != um.end(); i++){
            cout<<i->first<<"  "<<i->second.first<<"  "<<i->second.second<<endl;
            if(i->second.first == 1){
                if(ans == -1){
                    ans = i->second.second;
                }
                else{
                    if(i->second.second < ans)
                        ans = i->second.second;
                }
            }
        }
        return ans;
    }

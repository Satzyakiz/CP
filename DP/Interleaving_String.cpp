// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

map<pair<string,string>,bool> um;
bool helper(string s1,string s2,string s3){
    if(s3.size() <= 0)
        return true;
    if(s1.size() == 0)
        return s2 == s3;
    if(s2.size() == 0)
        return s1 == s3;

    if(um.find({s1,s2}) != um.end())
        return um[{s1,s2}];

    if(s3[0] == s1[0] && s3[0] == s2[0])
        return um[{s1,s2}] = (helper(s1.substr(1),s2,s3.substr(1)) || helper(s1,s2.substr(1),s3.substr(1)));
    else if(s3[0] == s1[0])
        return um[{s1,s2}] = helper(s1.substr(1),s2,s3.substr(1));
    else if(s3[0] == s2[0])
        return um[{s1,s2}] = helper(s1,s2.substr(1),s3.substr(1));
    else
        return um[{s1,s2}] = false;
}
bool isInterleave(string s1, string s2, string s3) {
    um.clear();
    int m = s1.size(), n = s2.size(), o = s3.size();
    if(o != m+n)
        return false;
    return helper(s1,s2,s3);
}

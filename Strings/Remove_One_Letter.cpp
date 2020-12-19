// Given two strings s0 and s1, return whether you can obtain s1 by
// removing 1 letter from s0.
// Input
// s0 = "hello"
// s1 = "hello"
// Output
// false
// Input
// s0 = "hello"
// s1 = "helo"
// Output
// true

bool solve(string s0, string s1) {
    int i=0, j=0,count=0;
    if(s0.size() - s1.size() != 1) return false;
    if(s1.size() == 0) return true;
    while(i < s0.size() && j < s1.size()){
        if(s0[i] != s1[j]){
            if(count == 1) return false;
            count++;
            i++;
        }else{
            i++, j++;
        }
    }
    if(j == s1.size())
        return (i == s0.size() - 1 || i == s0.size());
    return count == 1;
}

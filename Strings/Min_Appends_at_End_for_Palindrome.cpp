// Given a string A consisting of lowercase characters.
//
// We need to tell minimum characters to be appended (insertion at end)
// to make the string A a palindrome.
//
// Input 1:
//
//  A = "abede"
// Input 2:
//
//  A = "aabb"
//
// Output 1:
//
//  2
// Output 2:
//
//  2

int getMin(int id, string &s)
{
    if(id == s.length()-1) return 0;

    int j = s.length()-1;
    int i = id;
    bool pal = true;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            pal = false;
            break;
        }
        i++,j--;
    }
    if(pal) return 0;

    return (i-id+1) + getMin(i+1, s);

}
int Solution::solve(string A) {

    return getMin(0, A);
}

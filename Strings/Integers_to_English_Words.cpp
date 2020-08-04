// Convert a non-negative integer to its english words representation. 
// Given input is guaranteed to be less than 231 - 1.
//
// Example 1:
//
// Input: 123
// Output: "One Hundred Twenty Three"
// Example 2:
//
// Input: 12345
// Output: "Twelve Thousand Three Hundred Forty Five"
// Example 3:
//
// Input: 1234567
// Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// Example 4:
//
// Input: 1234567891
// Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety On

vector<string> no{"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
vector<string> tens{"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
vector<string> gtens{"", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
string helper(int x){
    string ans = "";
    if(x / 100){
        ans += no[x/100] + " Hundred";
        x = x % 100;
    }
    if(x >= 11 && x < 20){
        return ans + gtens[x - 10];
    }
    if(x / 10){
        ans += tens[x/10];
        x = x % 10;
    }
    if(x)
        ans += no[x];
    return ans;
}
string numberToWords(long num) {
    if(num == 0)
        return "Zero";
    vector<long> arr {1000000000, 1000000, 1000};
    vector<string> str{" Billion", " Million", " Thousand"};
    string ans = "";
    for(int i=0; i < arr.size() && num; i++){
        int x = num / arr[i];
        if(x){
            ans += helper(x) + str[i];
            num %= arr[i];
        }

    }
    if(num){
        ans += helper(num);
    }
    while(ans.front() == ' ')
        ans.erase(ans.begin());
    return ans;
}

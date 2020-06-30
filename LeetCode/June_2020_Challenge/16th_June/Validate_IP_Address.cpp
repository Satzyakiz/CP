// Example 1:
//
// Input: IP = "172.16.254.1"
// Output: "IPv4"
// Explanation: This is a valid IPv4 address, return "IPv4".
// Example 2:
//
// Input: IP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// Output: "IPv6"
// Explanation: This is a valid IPv6 address, return "IPv6".
// Example 3:
//
// Input: IP = "256.256.256.256"
// Output: "Neither"
// Explanation: This is neither a IPv4 address nor a IPv6 address.

bool isValidIpV4(string& ip) {
    if (count(ip.begin(), ip.end(), '.') != 3) {return false;}
    istringstream ss(ip);
    string num;
    int count = 0;
    while(getline(ss, num, '.')) {
        count ++;
        int len = num.size();
        if (len == 0 || len > 3) {return false;}
        if(len > 1 && num[0] == '0') {return false;}
        int val = 0;
        for (char c : num) {
            if(!isdigit(c)) {return false;}
            val = val * 10 + (c-'0');
            if(val > 255) {return false;}
        }
    }
    if(count != 4) {return false;}
    return true;
}

bool isValidIpV6(string& ip) {
    if (count(ip.begin(), ip.end(), ':') != 7) {return false;}
    istringstream ss(ip);
    string num;
    string validChar = "0123456789abcdefABCDEF";
    int count = 0;
    while(getline(ss, num, ':')) {
        count ++;
        int len = num.size();
        if (len == 0 || len > 4) {return false;}
        for (char c : num) {
            if (!isalnum(c) || validChar.find(c) == string::npos) { return false; }
        }
    }
    if(count != 8) {return false;}
    return true;
}

string validIPAddress(string IP) {
    if (isValidIpV4(IP)) { return "IPv4"; }
    if (isValidIpV6(IP)) { return "IPv6"; }
    return "Neither";
}

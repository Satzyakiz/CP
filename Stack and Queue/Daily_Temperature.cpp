
// Given a list of daily temperatures T, return a list such that,
// for each day in the input, tells you how many days you would have
// to wait until a warmer temperature. If there is no future day for
// which this is possible, put 0 instead.
//
// For example, given the list of temperatures
// T = [73, 74, 75, 71, 69, 72, 76, 73],
// your output should be [1, 1, 4, 2, 1, 1, 0, 0].

//Variant of Next Greater Element

vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n,0);
        stack<int> s;
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!s.empty()){
                if(T[s.top()] > T[i]){
                    break;
                }else{
                    s.pop();
                }
            }
            if(s.empty())
                ans[i] = 0;
            else
                ans[i] = s.top() - i;
            s.push(i);
        }
        return ans;
    }

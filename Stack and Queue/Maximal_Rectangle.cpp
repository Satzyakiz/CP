// Given a 2D binary matrix filled with 0's and 1's,
// find the largest rectangle containing only 1's and return its area.
//
// Example:
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int mah(vector<int> &arr){
    int maxArea = -1,area = 0,i=0, n = arr.size(),top,k;
    stack<int> s;
    while(i<n){
        if(s.empty() || arr[s.top()] <= arr[i]){
            s.push(i++);
        }else{
            top = s.top();
            s.pop();
            k = s.empty() ? i : i - s.top() - 1;
            area = arr[top] * k;
            maxArea = max(area,maxArea);
        }
    }

    while(!s.empty()){
        top = s.top();
        s.pop();
        k = s.empty() ? i : i - s.top() - 1;
        area = arr[top] * k;
        maxArea = max(area,maxArea);
    }
    return maxArea;
}
int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int maxVal = 0;
    vector<int> arr(m);
    for(int j=0; j<m; j++){
        arr[j] = M[0][j];
    }
    maxVal = mah(arr);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(M[i][j] == 0)
                arr[j] = 0;
            else{
                arr[j] += 1;
            }
        }
        int area = mah(arr);
        maxVal = max(maxVal,area);
    }
    return maxVal;
}


// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
//
// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]


static bool Compare(vector<int> &a,vector<int> &b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),Compare);
        for(vector<int> x: people){
            ans.insert(ans.begin()+x[1],x);
        }
        return ans;
    }

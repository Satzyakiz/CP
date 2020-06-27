// Given a binary tree, return the vertical order traversal of its nodes values.
//
// For each node at position (X, Y), its left and right children respectively
// will be at positions (X-1, Y-1) and (X+1, Y-1).
//
// Running a vertical line from X = -infinity to X = +infinity, whenever the
// vertical line touches some nodes, we report the values of the nodes in order
// from top to bottom (decreasing Y coordinates).
//
// If two nodes have the same position, then the value of the node that is
// reported first is the value that is smaller.
//
// Return an list of non-empty reports in order of X coordinate.  Every
// report will have a list of values of nodes.
//
// Input: [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
//
// Input: [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    map<int,vector<pair<int,int>>> m;
    queue<pair<TreeNode *,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        int k = q.size();
        while(k--){
            TreeNode *temp = q.front().first;
            int level = q.front().second.first;
            int height = q.front().second.second;
            q.pop();
            m[level].push_back({height,temp->val});
            if(temp->left)
                q.push({temp->left,{level-1,height+1}});
            if(temp->right)
                q.push({temp->right,{level+1,height+1}});
        }
    }
    for(auto itr=m.begin(); itr !=m.end(); itr++){
        sort(itr->second.begin(),itr->second.end());
        vector<int> v;
        for(auto x: itr->second){
            v.emplace_back(x.second);
        }
        ans.emplace_back(v);
    }
    return ans;
}

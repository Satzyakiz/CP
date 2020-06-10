
// Input: [1,2,3,null,5,null,4]
// Output: [1, 3, 4]
// Explanation:
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//

// Using DFS:
void dfs(TreeNode *root,int level,vector<int> &ans){
        if(!root) return;
        if(level >= ans.size()){
            ans.emplace_back(root->val);
        }
        dfs(root->right,level+1,ans);
        dfs(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }
// Using Level Order Traversal Concept:
vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> views;
        queue<TreeNode*> q;
        q.push(root);
        int level_size = 0;
        while(!q.empty()) {
            level_size = q.size();
            views.push_back(q.back() -> val);
            while(level_size--) {
                TreeNode* node = q.front();
                q.pop();
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
            }
        }
        return views;
    }

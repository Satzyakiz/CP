// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given undirected graph will be like this:
//   1
//  / \
// 2 - 3
// Example 2:
// Input: [[1,2], [2,3], [3,4], [1,4], [1,5]]
// Output: [1,4]
// Explanation: The given undirected graph will be like this:
// 5 - 1 - 2
//     |   |
//     4 - 3

int find(vector<int> &parent,int x){
        if(x != parent[x]){
            parent[x] = find(parent,parent[x]);
        }
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++)
            parent[i] = i;
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            int par_u = find(parent,u), par_v = find(parent,v);
            if(par_u == par_v)
                return e;
            else
                parent[par_u] = par_v;
        }
        return {};
    }

//Recursive Inorder Approach
TreeNode *prev;
    bool check(TreeNode *root){
        if(root == NULL)
            return true;
        if(check(root->left) == false)
            return false;
        if(prev != NULL){
            if(prev->val >= root->val)
                return false;
        }
        prev = root;
        return check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        prev = NULL;
        return check(root);
    }

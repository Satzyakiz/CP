// Given a Binary Tree A consisting of N nodes.
//
// You need to find all the cousins of node B.
//
// Siblings should not be considered as cousins.
// Try to do it in single traversal.
// You can assume that Node B is there in the tree A.
// Order doesn't matter in the output.

// Example Input
// Input 1:
//
//  A =
//
//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7
//
//
// B = 5
//
// Input 2:
//
//  A =
//             1
//           /   \
//          2     3
//         / \ .   \
//        4   5 .   6
//
//
// B = 1
//
// Example Output
// Output 1:
//
//  [6, 7]
// Output 2:
//
//  []


int getParent(TreeNode *A,int B){
    if(!A)
        return -1;
    if(A->left && A->left->val == B)
        return A->val;
    if(A->right && A->right->val == B){
        return A->val;
    }
    return max(getParent(A->left,B), getParent(A->right,B));
}
int getLevel(TreeNode *A,int B,int level = 0){
    if(!A)
        return -1;
    if(A->val == B){
        return level;
    }
    return max(getLevel(A->left,B,level+1),getLevel(A->right,B,level+1));
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(A->val == B)
        return {};
    int parent = getParent(A,B);
    int level = getLevel(A,B);
    vector<int> ans;
    queue<pair<TreeNode *,int>> q;
    q.push({A,-1});
    int l = 0;
    while(!q.empty()){
        int k = q.size();
        while(k--){
            TreeNode *temp = q.front().first;
            int par = q.front().second;
            q.pop();
            if(temp->left){
                q.push({temp->left,temp->val});
            }
            if(temp->right){
                q.push({temp->right,temp->val});
            }
            if(l == level){
                if(par != parent){
                    ans.emplace_back(temp->val);
                }
            }
        }
        l++;
        if(l > level)
            break;
    }

    return ans;
}

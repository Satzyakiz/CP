// Given an integer n, generate all structurally unique BST's
// (binary search trees) that store values 1 ... n.
//
// Example:
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

    vector<TreeNode *> helper(int start,int end){
        vector<TreeNode *> ans;
        if(start > end)
            ans.push_back(NULL);
        else if(start == end)
            ans.push_back(new TreeNode(start));
        else{
            for(int i=start; i<= end; i++){
                vector<TreeNode *> left = helper(start,i-1);
                vector<TreeNode *> right = helper(i+1,end);
                for(int j=0; j<left.size(); j++){
                    for(int k=0; k<right.size(); k++){
                        TreeNode *root = new TreeNode(i);
                        root->left = left[j];
                        root->right = right[k];
                        ans.push_back(root);
                    }
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1,n);
    }

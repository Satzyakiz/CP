// Given the root of a binary tree, the level of its root is 1, the 
// level of its children is 2, and so on.
//
// Return the smallest level X such that the sum of all the values of
// nodes at level X is maximal.
//
// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation:
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
//
// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2


int maxLevelSum(TreeNode* root) {
    int maxSum = INT_MIN, ans = -1;
    queue<TreeNode *> q;
    q.push(root);
    int level = 1;
    while(!q.empty()){
        int k = q.size();
        int sum = 0;
        while(k--){
            TreeNode *temp = q.front();
            q.pop();
            sum += temp->val;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(sum > maxSum){
            maxSum = sum;
            ans = level;
        }
        level++;
    }
    return ans;
}

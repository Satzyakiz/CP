
// Given a binary tree, return the zigzag level order
// traversal of its nodes’ values. (ie, from left to right,
//   then right to left for the next level and alternate between).
//
// Example :
// Given binary tree
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return
//
// [
//          [3],
//          [20, 9],
//          [15, 7]
// ]

//Using 2 stacks
vector<vector<int>> zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    if(A == NULL) return ans;
    stack<TreeNode *> stk1;
    stack<TreeNode *> stk2;
    vector<int> tempArr;
    stk1.push(A);
    TreeNode *temp;
    while(!stk1.empty() || !stk2.empty()){
        while(!stk1.empty()){
            temp = stk1.top();
            stk1.pop();
            tempArr.emplace_back(temp->val);
            if(temp->left)
                stk2.push(temp->left);
            if(temp->right)
                stk2.push(temp->right);
        }
        if(tempArr.size() != 0)
            ans.emplace_back(tempArr);
        tempArr.clear();
        while(!stk2.empty()){
            temp = stk2.top();
            stk2.pop();
            tempArr.emplace_back(temp->val);
            if(temp->right)
                stk1.push(temp->right);
            if(temp->left)
                stk1.push(temp->left);
        }
        if(tempArr.size() != 0)
            ans.emplace_back(tempArr);
        tempArr.clear();
    }

    return ans;
}

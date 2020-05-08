// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
//
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
//
// We are given the root of a binary tree with unique values, and the values x and y
// of two different nodes in the tree.
//
// Return true if and only if the nodes corresponding to the values x and y are cousins.

// Example 1:
//
//
// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:
//
//
// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:
//
//
//
// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false

// ******************************************************************************
// Two nodes are cousin if they are on the same level but with different parent
// ******************************************************************************

//get the level of the given val
int getLevel(TreeNode *root,int x){
    if(root == NULL) return -1;
    TreeNode *curr = root;
    queue<TreeNode *> q;
    q.push(curr);
    int level = 0;
    while(!q.empty()){
        int k = q.size();  //k is used to identify the no of nodes in the current level
        while(k--){
            curr = q.front();
            q.pop();
            if(curr->val == x)
                return level;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
        level++;
    }
    return -1;
}

//get the parent of the given val
int getParent(TreeNode *root, int x){
    if(root == NULL) return -1;
    TreeNode *curr = root;
    queue<TreeNode *> q;
    q.push(curr);
    while(!q.empty()){
            curr = q.front();
            q.pop();
            if(curr->left && curr->left->val == x)
                return curr->val;
            else if(curr->left)
                q.push(curr->left);
            if(curr->right && curr->right->val == x)
                return curr->val;
            else if(curr->right)
                q.push(curr->right);
    }
    return -1;
}

    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val == x || root->val == y)
            return false;

        if(getLevel(root,x) == getLevel(root,y) && getParent(root,x) != getParent(root,y))
            return true;
        else
            return false;
    }

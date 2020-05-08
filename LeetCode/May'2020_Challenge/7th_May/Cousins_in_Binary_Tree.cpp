//Detailed in Trees folder.

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

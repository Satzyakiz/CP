
// In a complete binary tree every level, except possibly the last, 
// is completely filled, and all nodes in the last level are as far
// left as possible. It can have between 1 and 2h nodes inclusive at
// the last level h.
//
// If at any level a NULL is encountered, there cannot be any level or
// any further node in that level.

bool isCompleteTree(TreeNode* root) {
	queue<TreeNode *> q;
	q.push(root);
	bool NullPresent = false;
	while(!q.empty()){
		TreeNode *temp = q.front();
		q.pop();
		if(!temp)
			NullPresent = true;
		if(NullPresent && temp)
			return false;
		if(temp){
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return true;
}

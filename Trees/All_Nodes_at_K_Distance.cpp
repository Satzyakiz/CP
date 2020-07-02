// We are given a binary tree (with root node root), a target node, and 
// an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the
// target node.  The answer can be returned in any order.
//
//
//
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//
// Output: [7,4,1]
//
// Explanation:
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.

vector<int> ans;
unordered_map<int,vector<int>> um;
unordered_map<int,bool> visited;
void dfs(TreeNode *root){
	if(!root)
		return;
	if(root->left){
		um[root->val].push_back(root->left->val);
		um[root->left->val].push_back(root->val);
	}
	if(root->right){
		um[root->val].push_back(root->right->val);
		um[root->right->val].push_back(root->val);
	}
	dfs(root->left);
	dfs(root->right);
}
void get(int target,int K){
	if(visited.find(target) != visited.end())
		return;
	visited[target] = true;
	if(K == 0){
		ans.emplace_back(target);
		visited[target] = true;
		return;
	}
	for(auto &x: um[target]){
		get(x,K-1);
	}
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
	dfs(root);
	get(target->val,K);
	return ans;
}

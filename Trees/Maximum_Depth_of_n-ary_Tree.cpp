
// Given a n-ary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest
// path from the root node down to the farthest leaf node.

int getDepth(Node *root){
	if(root == NULL)
		return 0;
	int maxDepth = 0;
	for(auto itr = root->children.begin(); itr != root->children.end(); itr++){
		maxDepth = max(maxDepth, getDepth(*itr));
	}
	return maxDepth+1;
}
int maxDepth(Node* root) {
	return getDepth(root);
}

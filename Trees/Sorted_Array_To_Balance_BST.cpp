// struct TreeNode{
//     int val;
//     struct TreeNode *left,*right;
//     TreeNode(int x): val(x),left(NULL),right(NULL){}; //constructor
// }

//Recursive call
TreeNode *balancedBST(vector<int> A,int l,int r){
  if(l<=r){
    int mid = l+(r-l)/2;
    TreeNode *node = new TreeNode(A[mid]);
    node->left = balancedBST(A,0,mid-1);
    node->right = balancedBST(A,mid+1,r);
    return node;
  }
  return NULL;
}
TreeNode *sortedArrayToBST(vector<int> A){
  return balancedBST(A,0,A.size()-1);
}

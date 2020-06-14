// Given the sorted array: [-10,-3,0,5,9],
//
// One possible answer is: [0,-3,9,-10,null,5], which represents the
// following height balanced BST:
//
//       0
//      / \
//    -3   9
//    /   /
//  -10  5.

TreeNode *helper(vector<int> &nums,int l,int h){
        if(l > h)
            return NULL;
        int mid = l + (h-l)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums,l,mid-1);
        root->right = helper(nums,mid+1,h);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root;
        root = helper(nums,0,nums.size()-1);
        return root;
    }

//Complete Code
#include <bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left,*right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
} TreeNode;
void preorder(TreeNode *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
TreeNode *helper(vector<int> &arr,int l,int h){
    if(l>h) return NULL;
    int mid = l + (h-l)/2;
    TreeNode *root = new TreeNode(arr[mid]);
    root->left = helper(arr,l,mid-1);
    root->right = helper(arr,mid+1,h);
    return root;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    TreeNode *root = helper(arr,0,arr.size()-1);
    preorder(root);
    cout<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}

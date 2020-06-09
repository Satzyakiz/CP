// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7

// ===============================================
// Important
// root->left = helper(pre,pstart+1,inord,istart,k-1);
// root->right = helper(pre,pstart-istart+k+1,inord,k+1,iend);
// ===============================================
TreeNode *helper(vector<int> pre,int pstart,vector<int> inord,int istart,int iend){
        if(istart > iend)
            return NULL;
        TreeNode *root = new TreeNode(pre[pstart]);
        int k;
        for(int i = istart; i <= iend; i++){
            if(inord[i] == root->val){
                k = i;
                break;
            }
        }
        root->left = helper(pre,pstart+1,inord,istart,k-1);
        root->right = helper(pre,pstart-istart+k+1,inord,k+1,iend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,inorder,0,inorder.size()-1);
    }

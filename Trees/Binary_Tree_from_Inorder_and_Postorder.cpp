

// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
// ==============================================
// IMPORTANT
// root->left = helper(p, pStart, pStart+k-iStart-1, in, iStart, k-1);
// root->right = helper(p, pEnd - iEnd + k, pEnd-1, in, k+1, iEnd);
// ==============================================

TreeNode *helper(vector<int> p,int pStart,int pEnd,vector<int> in,int iStart,int iEnd){
        if(pStart > pEnd)
            return NULL;
        TreeNode *root = new TreeNode(p[pEnd]);
        int k;
        for(int i=iStart; i<=iEnd; i++){
            if(in[i] == root->val){
                k = i;
                break;
            }
        }
        root->left = helper(p, pStart, pStart+k-iStart-1, in, iStart, k-1);
        root->right = helper(p, pEnd - iEnd + k, pEnd-1, in, k+1, iEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
    }


// Input:
// 2
// 1 2 3
// 10 20 30 40 60
//
// Output:
// 1 2 3
// 10 20 40 60 30

// i) Print left Boundary
// ii) Print the leaves from left to right
// iii) print Right Boundary recursively(from bottom to up)

void leaves(Node *root,vector<int> &ans){
    if(root == NULL)
        return;
    leaves(root->left,ans);
    if(!root->left && !root->right){
        ans.emplace_back(root->data);
        return;
    }
    leaves(root->right,ans);
}
void leftBoundary(Node *root,vector<int> &ans){
    if(root == NULL) return;
    if(root->left){
        ans.emplace_back(root->data);
        leftBoundary(root->left,ans);
    }else if(root->right){
        ans.emplace_back(root->data);
        leftBoundary(root->right,ans);
    }
}
void rightBoundary(Node *root,vector<int> &ans){
    if(root == NULL) return;
    if(root->right){
        rightBoundary(root->right,ans);
        ans.emplace_back(root->data);
    }else if(root->left){
        rightBoundary(root->left,ans);
        ans.emplace_back(root->data);
    }
}
vector <int> printBoundary(Node *root)
{
     vector<int> ans;
     if(root == NULL)
        return ans;
    ans.emplace_back(root->data);
    leftBoundary(root->left,ans);
    leaves(root->left,ans);
    leaves(root->right,ans);
    rightBoundary(root->right,ans);
}

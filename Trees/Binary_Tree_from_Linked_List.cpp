// Given a Linked List Representation of Complete Binary Tree. 
// The task is to construct the Binary tree.
// Note : The complete binary tree is represented as a linked list
// in a way where if root node is stored at position i, its left,
// and right children are stored at position 2*i+1, 2*i+2 respectively.
//
// Input:
// 2
// 5
// 1 2 3 4 5
// 5
// 5 4 3 2 1
// Output:
// 1 2 3 4 5
// 5 4 3 2 1

void convert(Node *head, TreeNode *&root) {
    // Your code here
    vector<TreeNode *> v;
    while(head){
        TreeNode *temp = new TreeNode(head->data);
        v.emplace_back(temp);
        head = head->next;
    }
    int n = v.size();
    for(int i=0; i<n/2; i++){
        if(2*i+1 < n)
            v[i]->left = v[2*i+1];
        if(2*i+2 < n)
            v[i]->right = v[2*i+2];
    }
    root = v[0];
}

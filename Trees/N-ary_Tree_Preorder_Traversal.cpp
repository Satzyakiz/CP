// Given an n-ary tree, return the preorder traversal of its nodes' values.


vector<int> preorder(Node* root) {
    stack<Node *> s;
    vector<int> ans;
    if(root == NULL)
        return ans;
    s.push(root);
    while(!s.empty()){
        Node *curr = s.top();
        s.pop();
        ans.emplace_back(curr->val);
        int n = curr->children.size();
        for(int i=n-1; i>=0; i--)
            s.push(curr->children[i]);

    }

    return ans;
}



vector<int> postorder(Node* root) {
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
        for(int i=0; i<n; i++)
            s.push(curr->children[i]);

    }
    reverse(ans.begin(),ans.end());
    return ans;
}

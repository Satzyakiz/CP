vector<vector<int>> levelOrder(Node* root) {
    queue<Node *> q;
    vector<vector<int>> ans;
    if(root == NULL)
        return ans;
    q.push(root);
    while(!q.empty()){
        int k = q.size();
        vector<int> tempAns;
        while(k--){
            Node *temp = q.front();
            q.pop();
            tempAns.emplace_back(temp->val);
            for(auto c: temp->children){
                q.push(c);
            }
        }
        ans.emplace_back(tempAns);
    }
    return ans;
}

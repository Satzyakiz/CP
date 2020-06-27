// Input:
// 2
// 1 3 2
// 10 20 30 40 60
// Output:
// 3 1 2
// 40 20 60 30

vector <int> bottomView(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == NULL)
        return ans;
    map<int,vector<pair<int,int>>> m;
    queue<pair<Node *,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        int k = q.size();
        while(k--){
            Node *temp = q.front().first;
            int level = q.front().second.first;
            int height = q.front().second.second;
            q.pop();
            m[level].push_back({height,temp->data});
            if(temp->left)
                q.push({temp->left,{level-1,height+1}});
            if(temp->right)
                q.push({temp->right,{level+1,height+1}});
        }
    }
    for(auto itr = m.begin(); itr != m.end(); itr++){
        auto p =  itr->second.back();
        ans.emplace_back(p.second);
    }
    return ans;

}

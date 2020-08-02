
// Given two words (beginWord and endWord), and a dictionary's word list,
// find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord
// is not a transformed word.

// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no
// possible transformation.

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string> s(wordList.begin(),wordList.end());
    if(s.count(endWord) == 0)
        return {};
    unordered_set<string> visited;
    vector<vector<string>> ans;
    queue<vector<string>> q;
    q.push({beginWord});
    bool found = false;

    while(!q.empty()){
        if(found)
            break;
        int k = q.size();
        for(string e: visited){
            s.erase(e);
        }
        visited.clear();
        while(k--){
            vector<string> path  = q.front();
            q.pop();
            string last = path.back();
            if(last == endWord){
                ans.push_back(path);
                found = true;
            }
            if(found)
                continue;
            for(int i=0; i<last.size(); i++){
                char ch = last[i];
                vector<string> newPath = path;
                for(char c='a'; c <= 'z'; c++){
                    last[i] = c;
                    if(s.count(last)){
                        newPath.push_back(last);
                        q.push(newPath);
                        newPath.pop_back();
                        visited.insert(last);
                    }
                }
                last[i] = ch;
            }
        }

    }

    return ans;
}

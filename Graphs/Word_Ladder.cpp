
// Given two words (beginWord and endWord), and a dictionary's word list, 
// find the length of shortest transformation sequence from beginWord to
// endWord, such that:
//
// Only one letter can be changed at a time.
// Each transformed word must exist in the word list.
//
// Example 1:
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output: 5
//
// Explanation: As one shortest transformation is
// "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Example 2:
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: 0
//
// Explanation: The endWord "cog" is not in wordList, therefore
// no possible transformation.

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while(!q.empty()){
            ++ans;
            int k = q.size();
            while(k--){
                string temp = q.front();
                q.pop();
                for(int i=0; i<temp.size(); i++){
                    char ch = temp[i];
                    for(char c = 'a' ; c <= 'z'; c++){
                        temp[i] = c;
                        if(temp == endWord)
                            return ans+1;
                        if(s.count(temp) == 0)
                            continue;
                        q.push(temp);
                        s.erase(temp);
                    }
                    temp[i] = ch;
                }
            }
        }

        return 0;
    }

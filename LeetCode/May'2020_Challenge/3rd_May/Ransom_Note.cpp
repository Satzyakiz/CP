// Given an arbitrary ransom note string and another string
// containing letters from all the magazines, write a function
// that will return true if the ransom note can be constructed
// from the magazines ; otherwise, it will return false.
//
// Each letter in the magazine string can only be used once in your ransom note.
//
//
//
// Example 1:
//
// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:
//
// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:
//
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() == 0 && ransomNote.size() == 0) return true;
        if(magazine.size() < ransomNote.size()) return false;
        multiset<char> s;
        for(char c: magazine){
            s.insert(c);
        }
        for(char c: ransomNote){
            if(s.empty()) return false;
            if(s.find(c) == s.end()) return false;
            else{
                s.erase(s.find(c));
            }
        }
        return true;
    }

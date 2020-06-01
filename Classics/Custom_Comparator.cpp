// Given a vector containing name of N student (in lowercase letters)
// and their marks in an exam. The task is to sort the students with
// respect to their marks (student with highest marks will be on top).
// If marks are same, consider lexicographic sorting for names.

// Input:
// 1
// 4
// michal 56
// john 100
// abbas 98
// jordan 45
//
// Output:
// john 100
// abbas 98
// michal 56
// jordan 45

bool Compare(pair<string,int> p1, pair<string,int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}
vector<pair<string, int>> sortMarks(vector<pair<string, int>> v, int N){
    sort(v.begin(),v.end(),Compare);
    return v;
}

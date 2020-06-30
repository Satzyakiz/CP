// Given an array w of positive integers, where w[i] describes the weight of 
// index i(0-indexed), write a function pickIndex which randomly picks an index
// in proportion to its weight.
//
// For example, given an input list of values w = [2, 8], when we pick up
// a number out of it, the chance is that 8 times out of 10 we should pick
// the number 1 as the answer since it's the second element of the
// array (w[1] = 8).

vector<int> s;
Solution(vector<int>& w) {
    for (int ind : w){
        if(s.empty())
            s.push_back(ind);
        else
            s.push_back(ind + s.back());
    }
}

int pickIndex() {
    int x = s.back();
    int index = rand() % x;
    auto it = upper_bound(s.begin(), s.end(),index);
    return it - s.begin();
}

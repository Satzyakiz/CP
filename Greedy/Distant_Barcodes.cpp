// 
// In a warehouse, there is a row of barcodes,
// where the i-th barcode is barcodes[i].
//
// Rearrange the barcodes so that no two adjacent barcodes are equal.
// You may return any answer, and it is guaranteed an answer exists.
//
// Example 1:
//
// Input: [1,1,1,2,2,2]
// Output: [2,1,2,1,2,1]
// Example 2:
//
// Input: [1,1,1,1,2,2,3,3]
// Output: [1,3,1,3,2,1,2,1]

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int,int> um;
    set<pair<int,int>> s;
    for(int &x: barcodes)
        um[x]++;
    for(auto itr = um.begin(); itr != um.end(); itr++){
        s.insert({itr->second,itr->first});
    }
    int pos = 0;
    for(auto i = s.rbegin(); i != s.rend(); i++){
        for(int j=0; j < i->first; j++, pos += 2){
            if(pos >= barcodes.size())
                pos = 1;
            barcodes[pos] = i->second;
        }
    }
    return barcodes;
}

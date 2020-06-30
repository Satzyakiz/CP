// Given a list of airline tickets represented by pairs of departure and 
// arrival airports [from, to], reconstruct the itinerary in order. All of the
// tickets belong to a man who departs from JFK. Thus, the itinerary must
// begin with JFK.
//
// Example 1:
//
// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
// Example 2:
//
// Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
// Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
//              But it is larger in lexical order.

map<string, multiset<string>> targets;
vector<string> route;

vector<string> findItinerary(vector<vector<string>> tickets) {
    for (auto t : tickets){
        targets[t[0]].insert(t[1]);
    }
    visit("JFK");
    reverse(route.begin(),route.end());
    return route;
}

void visit(string now) {
    while (targets[now].size()) {
        string next = *targets[now].begin();
        targets[now].erase(targets[now].begin());
        visit(next);
    }
    route.push_back(now);
}


// Example:
//
// Input: [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

int maxProfit(vector<int>& prices) {
    int buy, sell, prevBuy, prevSell;
    sell = prevBuy = prevSell = 0;
    buy = INT_MIN;
    for(int p: prices){
        prevBuy = buy;
        buy = max(buy, prevSell - p);
        prevSell = sell;
        sell = max(sell, prevBuy + p);
    }
    return sell;
}

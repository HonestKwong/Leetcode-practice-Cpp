class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX;
        int price = 0;
        // for(int i=0; i<prices.size(); i++){
        for(auto &x : prices){
            cost = min(cost, x);
            price = max(price, x - cost);
        }
        return price;

    }
};
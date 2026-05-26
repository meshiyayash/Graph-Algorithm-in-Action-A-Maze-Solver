class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sell=prices[0],profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<buy){
                profit=max(profit,sell-buy);
                buy=prices[i];
                sell=prices[i];
            } 
            if(prices[i]>sell){
                sell=prices[i];
            }
        }
        profit=max(profit,sell-buy);
        return profit;
    }
};
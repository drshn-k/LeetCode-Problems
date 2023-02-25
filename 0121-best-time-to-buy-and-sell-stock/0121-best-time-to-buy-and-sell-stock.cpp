class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min1 = INT_MAX;
        int max1 = INT_MIN;
        int price = 0 ; 
        for(int i = 0 ; i < prices.size() ; i++){
            
            if(prices[i] < min1) {
                min1 = prices[i];
                max1 = INT_MIN;
            }
            
            if(prices[i] > max1) max1 = prices[i];
            
            price = max(price , max1 - min1);
            
        }
        
        return price;
    }
};
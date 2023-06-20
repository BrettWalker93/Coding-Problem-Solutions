// LeetCode automatically includes appropriate libraries

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int total = 0;
        
        int val = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            
            if (prices[i] <= val) {
                val = prices[i];
            } else {
                total += prices[i] - val;
                val = prices[i];
            }
            
        }
        
        return total;
        
    }
};

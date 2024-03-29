class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        vector<int> answer = {0, 0};
        
        for (int i = 0; i < n; i++) {
            
            int a = nums[i];
            
            int t = target - a;
            
            for (int j = i +1; j < n; j++) {
                
                if (nums[j] == t) {
                    
                    return {i, j}
                }
                
            }
                       
        }
        
        return {0, 0};
    }
};

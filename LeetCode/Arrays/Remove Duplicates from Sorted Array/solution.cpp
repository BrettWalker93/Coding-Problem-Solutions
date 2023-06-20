//LeetCode automaticall includes appropriate libraries

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int>::iterator ip = std::unique(nums.begin(), nums.begin() + nums.size());
        
        nums.resize(std::distance(nums.begin(), ip));
                    
        return nums.size();
        
    }
};

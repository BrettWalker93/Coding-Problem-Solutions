class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        
        vector<int> answer = {-1,-1};
        
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            
            map.insert({nums[i],i});
            
        }
        
        for (int j = 0; j < n; j++) {
            
            int t = target - nums[j];
            
            if (map.find(t) != map.end()) {
                
                if (map.at(t) != j) {
                    answer[0] = j;
                    answer[1] = map.at(t);
                    goto re;
                }
            }
            
        }
        
        re: return answer;
        
    }
};

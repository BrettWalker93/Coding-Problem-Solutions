class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k % n;
        
        vector<int> rotated(n, 0);
        
        for (int i = 0; i < n; i++) {           
            rotated[(i + k) % n] = nums[i];
        }
        
        nums = rotated;
        
    }
};

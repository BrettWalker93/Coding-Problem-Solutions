class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        if (nums.size() > std::set<int>(nums.begin(), nums.end() ).size()) return true;
        return false;
        
    }
};

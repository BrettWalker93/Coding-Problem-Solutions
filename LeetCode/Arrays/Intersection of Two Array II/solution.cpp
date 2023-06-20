class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int, pair<int, int>> intersect_map;
        
        for (int n : nums1) {
            
            if (intersect_map.count(n)) intersect_map.at(n).first++;
            else intersect_map[n] = make_pair(1, 0);
            
        }
        
        for (int m : nums2) {
            if (intersect_map.count(m)) intersect_map.at(m).second++;
            else intersect_map[m] = make_pair(0, 1);
        }
        
        vector<int> intersect;
        
        for (auto kvpair : intersect_map) {
            
            int f = kvpair.second.first;
            int s = kvpair.second.second;
            
            if (s * f > 0) {
                           
                for (int i = 0; i < min(s, f); i++) {
                    intersect.push_back(kvpair.first);
                }
                
            }            
        }
        
        return intersect;
        
    }
};

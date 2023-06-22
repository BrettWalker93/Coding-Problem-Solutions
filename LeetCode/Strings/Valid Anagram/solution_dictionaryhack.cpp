class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n = s.size();
        
        if (n != t.size()) return false;
        
        vector<int> count(26, 0);
        
        for (int i = 0; i < n; i++) {
            
            count[s[i] - 'a'] += 1;
            count[t[i] - 'a'] -= 1;
            
        }
        
        for (int c : count) {
            
            if (c) return false;
        }
        return true;
    }
};

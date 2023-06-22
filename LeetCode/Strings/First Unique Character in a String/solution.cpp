class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> mymap;
        
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            
            char c = s[i];
            
            if (mymap.count(c)) mymap[c]++;
            else mymap.insert({c, 1});
            
        }
        
        for (int i = 0; i < n; i++) {
            
            char c = s[i];
            
            if (mymap[c] == 1) return i;
            
        }
        
        return -1;
    }
};

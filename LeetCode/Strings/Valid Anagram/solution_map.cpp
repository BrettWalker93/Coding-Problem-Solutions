class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char, int> smap;
        map<char, int> tmap;
        
        int n = s.size();
        
        if (n != t.size()) return false;
        
        for (int i = 0; i < n; i++) {
            
            if (smap.count(s[i])) smap[s[i]]++;
            else smap.insert({s[i], 1});
            
            if (tmap.count(t[i])) tmap[t[i]]++;
            else tmap.insert({t[i], 1});
        }
        
        if (tmap == smap) return true;
        
        return false;
    }
};

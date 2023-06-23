class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        
        for (string s : strs) {
            
            if (s.size() < prefix.size()) {
                prefix = prefix.substr(0, s.size());
            }

                                                
            for (int i = 0; i < prefix.size(); i++) {

                if (prefix[i] != s[i]) {

                    if (i == 0) return "";
                    prefix = prefix.substr(0, i);


                }
                    
            }
                
        }
                                        
        return prefix;
        
    }
};

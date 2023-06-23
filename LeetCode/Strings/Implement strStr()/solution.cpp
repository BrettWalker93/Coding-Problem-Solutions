class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int idx = -1;
        
        for (int i = 0; i < haystack.size(); i++) {
            
            if (haystack[i] == needle[0]) {
                
                bool found = true;

                int j = 1;
                
                while(j < needle.size()) {
                    
                    if (haystack[i+j] != needle[j]) {
                        found = false;
                        break;
                    }
                                                     
                    j++;
                }
                
                if (found) return i;
                
            }
            
        }
        
        return -1;
        
    }
};

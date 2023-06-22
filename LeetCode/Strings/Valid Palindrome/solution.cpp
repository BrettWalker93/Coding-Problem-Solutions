class Solution {
public:
    bool isPalindrome(string s) {
        
        // backward iterator
        int b = s.size() - 1;

        //forward iterator
        int f = 0;
        
        while (f < b) {
            
            while (!isalnum(s[f]) && f < b) f++;
            while (!isalnum(s[b]) && f < b) b--;
            
            if (tolower(s[f]) != tolower(s[b])) return false;
            
            f++;
            b--;
            
        }
        
        return true;
    }
};

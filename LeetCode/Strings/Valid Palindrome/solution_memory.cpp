class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            
            if (!isalnum(s[i]) or s[i] == ' ') {
                s.erase(i,1);
                n--;
                i--;
            }
            else s[i] = tolower(s[i]);            
        }              

        for (int i = 0; i < n / 2; i++) {            
            if (s[i] != s[n - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};

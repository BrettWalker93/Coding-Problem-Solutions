class Solution {
public:
    int reverse(int x) {
        
        bool isneg = false;
        
        string s = to_string(x);
        
        if (s[0] == '-') {
            
            isneg = true;
            
            s = s.substr(1);
            
        }
        
        int n = s.size();
        
        for (int i = 0; i < n / 2; i++) {
            
            char tmp = s[i];
            
            s[i] = s[n - i - 1];
            
            s[n - i - 1] = tmp;
            
        }   
        
        try {
            
            if (isneg && s == "2147483648") return -2147483648;
            
            int ans = stoi(s);
            
            if (isneg) ans *= -1;
            return ans;                        
        }
        
        catch(exception& e) {
            return 0;
        }             
        
    }
};

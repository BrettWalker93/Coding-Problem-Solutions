class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.size();
        
        int i = 0;
        
        long ans = 0;
        
        int positive = 0;
        
        bool looking = false;
        
        while (i < n) {                       
            char c = s[i];
            
            if (not looking) {
                
                if (c == '-') {
                    positive = -1;
                    looking = true;
                }
                else if (c == '+') {
                    positive = 1;
                    looking = true;
                }
                
                else if (!isdigit(c) && c != ' ') return 0;
                
                else if (isdigit(c)) {
                    
                    ans = c - '0';
                    looking = true;
                    
                }
                
            }
            
            else if (isdigit(c)) {

                if (positive == 0) positive = 1;
                
                try {
                    
                    int this_digit = c - '0';
                    
                    ans = ans*10 + this_digit * positive;
                    
                    if (ans > INT_MAX || ans < INT_MIN) throw (0);
                    
                }
                catch (int e) {
                    
                    if (positive == 1) return INT_MAX;
                    else return INT_MIN;
                    
                }
                
            }
            
            else return ans;
            

            i++;            
        }
        
        return ans;
        
    }
};

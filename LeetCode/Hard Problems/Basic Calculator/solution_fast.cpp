class Solution {
public:
    int calculate(string s) {

        /*
        keep a running total of the left side of additions/subtractions
        store this total in a stack when entering parenthesis
        pop the stack when closing parentheses
        */
        
        vector<int> val, signs;
        int sign = 1;
        int ans = 0;
        int v = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (isalnum(c)) {
                v = v * 10 + (c - '0');
            }
            else if (c == '+' or c == '-') {
                ans += v * sign;
                v = 0;
                sign = 1;
                if (c == '-') sign = -1;
            }
            else if (c == '(') {
                val.push_back(ans);
                signs.push_back(sign);
                sign = 1;
                ans = 0;
            }
            else if (c == ')') {
                ans += sign * v;
                ans *= signs.back();
                ans += val.back();
                signs.pop_back();
                val.pop_back();
                v = 0;

            }
        }

        return ans + v * sign;

    }

};

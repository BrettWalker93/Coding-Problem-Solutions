class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        bool go = true;
        int idx = digits.size() - 1;

        while (go) {

            if (idx == 0) {
                if (digits[0] == 9 && go) {
                    digits[0] = 0;
                    digits.insert(digits.begin(), 1, 1);
                    
                } else digits[0]++;
                go = false;
            } else if (digits[idx] == 9) {
                digits[idx] = 0;
            } else {
                digits[idx]++;
                go = false;
            }
            idx--;            
        }
        
        return digits;
        
    }
};

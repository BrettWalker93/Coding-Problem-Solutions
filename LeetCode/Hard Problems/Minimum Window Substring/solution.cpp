class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        a sliding window moves along the string, keeping a tally of target letters
        when the tally matches the target (measured by count), we have a valid substring, 
        then, we can shorten the window until the string is no longer valid. 
        keep lengthening and shortening the window until the end of the string is reached.
        once the end is reached, we either have a minimal substring or no substring        
        */

        int count = t.size();
        int n = s.size();
        if (count > n) return "";
        int left = 0, start = 0, right = 0, minlen = INT_MAX;        
        int tally[128] = {[0 ... 127] = 0};

        //initialize tally
        for (char c : t) {
            tally[c]++;
        }

        while (right < n) {
            char c = s[right];
            if (tally[c] > 0) count--;
            tally[c]--;
            right++;

            while (count == 0) {
                if (right - left < minlen) {
                    start = left;
                    minlen = right - left;
                }
                char si = s[left];
                tally[si]++;
                if (tally[si] > 0) count++;
                left++;
            }            
        }
        return (minlen == INT_MAX) ? "" : s.substr(start, minlen);

    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        a sliding window moves along the string, keeping a tally of target letters
        when the tally matches the target, we have a valid substring
        if we each the end of the string, we increase the window size, and begin sliding the other way
        if the window size reaches the size of the string and an answer isn't found, we return an empty string
        */

        int n = s.size();
        int m = t.size();
        int winlen = m;
        int numzero = 0; //when a tally reaches zero, numzero will increment. upon reaching maxzero, all tallies will be zero and we have a valid substr
        int maxzero = 0;
        int tally[128] = {[0 ... 127] = INT_MIN};

        if (m > n) return "";

        //initialize tally
        for (char c : t) {
            if (tally[c] == INT_MIN) {
                tally[c] = 1;
                maxzero++;
            }
            else tally[c]++;
        }

        for (int i = 0; i < winlen; i++) {
            if (tally[s[i]] != INT_MIN) {
                tally[s[i]]--;
                if (tally[s[i]] == 0) numzero++;
            }
        }

        if (numzero == maxzero) return s.substr(0, winlen);

        int pos = 0;
        bool moveright = true;
        while (winlen < n) { //run until window is full length of string
            //what will be added and removed from the window
            char rem = '_';
            char add = '_';
            if (moveright) {
                rem = s[pos];
                add = s[pos + winlen];
                pos++;
            }
            else {
                add = s[pos-1];
                rem = s[pos + winlen - 1];
                pos--;
            }

            //remove this letter from window and increment tally if necessary
            if (tally[rem] != INT_MIN) {
                tally[rem]++;
                if (tally[rem] == 1) numzero--;
            }

            //add this letter to the window and decrement tally if necessary
            if (tally[add] != INT_MIN) {
                tally[add]--;
                if (tally[add] == 0) numzero++;
            }

            //valid substring?
            if (numzero == maxzero) return s.substr(pos, winlen);

            //edge reached?
            if (pos == (n - winlen) or (pos == 0 and !moveright)) {
                moveright = !moveright;
                
                char c = '_';
                //widen the window
                if (moveright) c = s[winlen];
                else {
                    c = s[n - winlen - 1];
                    pos--;
                } 
                if (tally[c] != INT_MIN) {
                    tally[c]--;
                    if (tally[c] == 0) numzero++;
                }
                winlen++;
                //valid?
                if (numzero == maxzero) return s.substr(pos, winlen);
            }

        }
        
        return "";

    }
};

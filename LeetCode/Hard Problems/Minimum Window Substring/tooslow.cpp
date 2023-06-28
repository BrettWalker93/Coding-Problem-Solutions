class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        use a sliding window to traverse the string and see if all necessary letters are in the window
        */

        int n = s.size();
        int m = t.size();
        int winlen = m;
        bool found = false;

        vector<int> target(m, 0);
        for (int i = 0; i < m; i++) {
            char c = t[i];
            for (int j = 0; j < m; j++) {
                if (t[j] == c) {
                    target[j]++;
                    break;
                }
            }
        }

        while (!found && winlen <= n) {
            //if the count vector = target vector, we have found a valid substring
            //otherwise, move the window to the right, check if any letters were lost, and see if any new letters are added

            //construct the initial count vector
            vector<int> count(m, 0);
            for (int i = 0; i < winlen; i++) {
                char c = s[i];
                for (int j = 0; j < m; j++) {
                    if (t[j] == c) {
                        count[j]++;
                        break;
                    }
                }
            }
        
            bool good = true;
            for (int letter = 0; letter < m; letter++) {
                if (count[letter] < target[letter]) good = false;
            }
            if (good) return s.substr(0, winlen);

            cout << "starting " << s.substr(0, winlen) << endl;
            //shift right
            for (int i = 0; i < n - winlen; i++) {
                cout << "shifting " << s.substr(i, winlen) << endl;
                char c = s[i];
                cout << "removing " << c << endl;
                for (int j = 0; j < m; j++) {
                    if (t[j] == c) {
                        count[j]--;
                        break;
                    }
                }
                c = s[i+winlen];
                cout << "adding " << c << endl;
                for (int j = 0; j < m; j++) {
                    if (t[j] == c) {
                        count[j]++;
                        break;
                    }
                }
                bool good = true;
                for (int letter = 0; letter < m; letter++) {
                    if (count[letter] < target[letter]) good = false;
                }
                if (good) return s.substr(i+1, winlen);  
                
            }

            winlen++;
        }

        return "";

    }
};

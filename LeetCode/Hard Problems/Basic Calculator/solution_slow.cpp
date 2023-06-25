class Solution {
public:
    int calculate(string s) {

        int ans = eval(s, 0).first;
        cout << "returning answer " << ans << endl;
        return ans;


    }

    pair<int, int> eval(string s, int idx) {
        int n = s.size();
        int l = 0;
        vector<int> singlenums = {};
        bool isneg = false;
        int r = 0;
        for (int i = idx; i < n; i++) {
            //cout << "i " << i << endl;           
            char c = s[i];
            //cout << "c " << c << endl;
            if (c == '(') {
                pair<int, int> cur = eval(s, i + 1);
                if (isneg) {
                    l -= cur.first;
                    isneg = false;
                }
                else l += cur.first;
                i = cur.second;
            }
            else if (c == ')') {
                return {l+r, i};
            }
            else if (c == '+') {

            }
            else if (c == '-') {
                if (s[i] + 1 == '(') {
                    pair<int, int> cur = eval(s, i + 1);
                    l += cur.first;
                    i = cur.second;
                }
                else {
                    //cout << "making negative" << endl;
                    isneg = true;
                }
            }
            else if (isalnum(c)) {
                singlenums.push_back(s[i] - '0');
                while(isalnum(s[i+1]) and i < n) {
                    i++;
                    singlenums.push_back(s[i]- '0');
                }
                r = makenum(singlenums);
                if (isneg) {
                    r *= -1;
                    isneg = false;
                }
                cout << "r " << r << endl;
                l += r;
                cout << "ans " << l << endl;
                r = 0;
                singlenums = {};
            }
            idx = i;
        }
        cout << "adding " << l << " to " << r << endl;
        if (isneg) l -= r;
        else l += r;
        return {l, idx};

    }

    int makenum(vector<int>& numlist) {
        int a = 0;
        int n = numlist.size();

        for (int i = 0; i < n; i++) {
            
            a = a * 10 + numlist[i];
        }

        return a;
    }

};

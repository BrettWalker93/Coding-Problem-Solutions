class Solution {
public:
    int calculate(string s) {

        vector<int> open;
        vector<pair<int, int>> par;
        bool haspar = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open.push_back(i);
            }
            else if (s[i] == ')') {
                int o = open.back();
                open.pop_back();
                int len = i - o + 1;
                s.replace(o, len, to_string(eval(s.substr(o, len))));
                i = i - len;
            }
        }

        return eval(s);
    }

    int makenum(vector<int>& numlist) {
        int a = 0;
        int n = numlist.size();

        for (int i = 0; i < n; i++) {
            a += numlist[i] * pow(10, n - 1 - i);
        }

        return a;
    }

    int eval (string s) {

        cout << "evaluating " << s << endl;

        int ans = 0;
        int n = s.size();
        int r = 0;
        vector<int> singlenums = {};
        bool isneg = false;

        for (int i = 0; i < n; i++) {
            while (s[i] == ' ' and i < n - 1)i++;
            if (isalnum(s[i])) {
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
                ans += r;
                cout << "ans " << ans << endl;
                r = 0;
                singlenums = {};
            }
            else if (s[i] == '-') {
                    if (isneg) isneg = false;
                    else isneg = true;
            }
            ans += r;           
        }
        cout << "returning " << ans << endl;
        return ans;
    }

};

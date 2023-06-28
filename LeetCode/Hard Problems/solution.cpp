class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        /*
        keep a count of each word in an unordered map
        iteratively check to see if a substring is in the map, decrement count by one, breaking if substring is not present or count is less than 1
        if successfully counting to the size of words, substring is valid and index can be stored
        */

      
        int m = s.size();
        int n = words.size();
        int l = words[0].size();
        vector<int> subs = {};
        unordered_map<string, int> count;

        for (string s : words) {
            if (count.count(s) == 0) {

                count.insert({s, 1});
                //cout << s << " " << count[s] << endl;
            }
            else count[s]++;
        }

        // string is too small to have a concatenated substring
        if (m < n * l) return subs;
        
        unordered_map copy = count;
        for (int i = 0; i < m - n * l + 1; i++) {
            copy = count;
            bool stop = false;
            int j = i;
            for (int k = 0; k < n; k++) {
                string ss = s.substr(j, l);
                
                if (copy.count(ss) == 0) {
                    break;
                }

                if (copy[ss] < 1) {
                    //cout << "here" << endl;
                    break;
                }
                else copy[ss]--;

                if (k == n - 1) {
                    subs.push_back(i);
                }

                j+=l;
            }
            

        }

        return subs;

        //

    }
};

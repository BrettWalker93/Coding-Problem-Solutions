class Solution {
public:
    int candy(vector<int>& ratings) {
        
        /*
        if the rating goes up, we must make sure we give this child more candy,
        keep track of how much (bonus) candy the previous child received, 
        so that successive increases in ranking can be given the appropriate candy.
        if a decrease in ranking occurs
            if the previous child didn't receive bonus candy, we can stairstep and be ok.
            otherwise,
                mark the spot which the descent starts, and then start from the end of the descent and work your way back, appropriately distributing candy.
        */

        int n = ratings.size();
        int candy = 0;
        int prev = ratings[0];
        int prevc = 0;
        int decstep = 0;

        for (int i = 1; i < n; i++) {
            int it = ratings[i];
            if (it > prev) {
                if (decstep > 0) prevc = 0;
                prevc++;
                candy += prevc;
                decstep = 0;
            }
            else if (it < prev) {
                if (prevc == 0) {
                    candy += 1 + decstep;
                    decstep++;
                }
                else if (i == n - 1) {}
                else {
                    cout << "here" << endl;
                    int j = i;
                    while (j < n - 1) {
                        if (ratings[j] <= ratings[j+1]) {
                            break;
                        }
                        else j++;
                    }
                    cout << "j " << j << endl;
                    int k = j;
                    int add = 0;
                    while (j > i) {
                        add++;
                        candy += add;
                        j--;
                    }
                    if (add >= prevc) candy += 1 + add - prevc;
                    i = k;
                    prevc = 0;
                    decstep = 0;
                    cout << "candy after descent loop " << candy << endl;
                    it = ratings[i];
                }
            }
            else {
                prevc = 0;
                decstep = 0;
            }
            prev = it;
            cout << it << ": " << candy << endl;
        }
        return candy + n;
    }
};

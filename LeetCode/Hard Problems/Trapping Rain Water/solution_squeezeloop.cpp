class Solution {
public:
    int trap(vector<int>& height) {

        /*
        use left and right pointer
        if one pointer is greater than the other, we know that any available space between will be filled.
        */

        int l = 0;
        int r = height.size() - 1;
        int lh = height[0];
        int rh = height[r];
        int total = 0;

        while (l < r) {
            if (lh < rh) {
                //move pointer along, adding any space to be filled.
                l++;
                int h = height[l];
                if (h > lh) lh = h;
                total += lh - h;
            }
            else {
                r--;
                int h = height[r];
                if (h > rh) rh = h;
                total += rh - h;
            }
        }


        return total;
    }
};

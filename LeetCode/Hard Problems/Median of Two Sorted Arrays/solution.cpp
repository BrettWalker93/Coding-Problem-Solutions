class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        /*
        for a sorted list of s members (indexing from 0), the median will be:
            when s is even: the average of positions (s / 2) - 1 and (s / 2)
            when s is odd: the (s / 2)th position

        */

        int n = nums1.size();
        int m = nums2.size();

        if (n == 0) {
            if (m % 2 == 0) {
                return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            }
            else return nums2[m / 2];
        }
        else if (m == 0) {
            if (n % 2 == 0) {
                return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            }
            else return nums1[n / 2];
        }

        bool iseven = ((m+ n) % 2 == 0);
        int one = 0;
        int two = 0;
        int pos = 0;
        bool exh1 = false;
        bool exh2 = false;
        int steps =  (n + m) / 2;
        if (iseven) steps--;

        while (steps > 0) {
            // if exhausted array
            if (exh1) {
                two++;
                steps--;
                continue;
            }
            else if (exh2) {
                one++;
                steps--;
                continue;
            }
            // try to move pointers
            if (nums1[one] <= nums2[two]) {
                one++;
                if (one >= n) exh1 = true;
            }
            else {
                two++;
                if (two >= m) exh2 = true;
            }
            steps--;
        }

        if (iseven) {
            if (!exh1 and !exh2) {
                //identify the right numbers
                if (nums1[one] <= nums2[two]) {
                    if (one == n - 1) return (nums1[one] + nums2[two]) / 2.0;
                    else {
                        if (nums1[one+1] < nums2[two]) return (nums1[one] + nums1[one+1]) / 2.0;
                        else return (nums1[one] + nums2[two]) / 2.0;
                    }
                }
                else {
                    if (two == m - 1) return (nums1[one] + nums2[two]) / 2.0;
                    else {
                        if (nums2[two+1] < nums1[one]) return (nums2[two] + nums2[two+1]) / 2.0;
                        else return (nums1[one] + nums2[two]) / 2.0;
                    }
                }
                return (nums1[one] + nums2[two]) / 2.0;
            }
            
            if (exh1) {
                return (nums2[two] + nums2[two+1]) / 2.0;
            }
            else {
                return (nums1[one] + nums1[one+1]) / 2.0;
            }
        }
        if (exh1) {
            return nums2[two];
        }
        else if (exh2) {
            return nums1[one];
        }
        return nums1[one] > nums2[two] ? nums2[two] : nums1[one];
    }
};

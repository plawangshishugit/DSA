//Optimized

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on smaller array
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n1 = nums1.size();
        int n2 = nums2.size();

        int low = 0;
        int high = n1;

        while(low <= high) {

            int cut1 = (low + high) / 2;

            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

            // Correct partition
            if(l1 <= r2 && l2 <= r1) {

                // Odd length
                if((n1 + n2) % 2 != 0) {

                    return max(l1, l2);
                }

                // Even length
                else {

                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }

            // Move left
            else if(l1 > r2) {

                high = cut1 - 1;
            }

            // Move right
            else {

                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
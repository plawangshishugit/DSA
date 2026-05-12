//Brute

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i =0; int j = 0;
        vector<int>temp;
        while(i<n1 && j<n2){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        if(i<n1){
            for(int t =i; t<n1; t++){
                temp.push_back(nums1[t]);
            }
        }
        if(j<n2){
            for(int t =j; t<n2; t++){
                temp.push_back(nums2[t]);
            }
        }
        int n = temp.size();
        if(n % 2 != 0){
            return double(temp[n/2]);
        }
        else{
            return ((double(temp[n/2]+ temp[(n-1)/2]))/double(2));
        }
    }
};
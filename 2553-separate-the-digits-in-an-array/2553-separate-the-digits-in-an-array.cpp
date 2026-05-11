class Solution {
private:
    vector<int>addDigit(int &num, vector<int>&ans){
        if(num <= 9){
            ans.push_back(num);
            return ans;
        }
        int rem = num % 10;
        int quo = num / 10;
        addDigit(quo, ans);
        ans.push_back(rem);
        return ans;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i =0; i<n; i++){
            addDigit(nums[i],ans);
        }
        return ans;
    }
};
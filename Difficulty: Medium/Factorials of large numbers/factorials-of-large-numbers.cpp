class Solution {
private:
    void mul(vector<int>& arr, int &size, int multiplier){
        int carry = 0;

        for(int i = 0; i < size; i++){
            int res = arr[i] * multiplier + carry;
            arr[i] = res % 10;
            carry = res / 10;
        }

        while(carry > 0){
            arr[size] = carry % 10;
            size++;
            carry /= 10;
        }
    }

public:
    vector<int> factorial(int n) {
        vector<int> arr(10000, 0);
        arr[0] = 1;

        int size = 1;

        for(int multiplier = 2; multiplier <= n; multiplier++){
            mul(arr, size, multiplier);
        }

        vector<int> ans;

        // reverse order
        for(int i = size - 1; i >= 0; i--){
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
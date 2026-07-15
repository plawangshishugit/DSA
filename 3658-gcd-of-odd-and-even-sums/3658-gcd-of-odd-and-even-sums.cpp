class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n*n;
        int sumEven = n*(n+1);
        int ans = 1;
        for(int i =1; i<=sumOdd; i++){
            if(sumOdd % i ==0 && sumEven % i ==0){
                ans = i;
            }
        }
        return ans;
    }
};
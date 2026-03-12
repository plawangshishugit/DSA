class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = -1;
        int n = capacity.size();
        for(int i =0; i<n; i++){
            if(capacity[i] >= itemSize){
                int temp = i;
                if(ans != -1){
                    if(capacity[temp] < capacity[ans]){
                        ans = temp;
                    }
                }
                else{
                    ans = temp;
                }
            }
        }
        return ans;
    }
};
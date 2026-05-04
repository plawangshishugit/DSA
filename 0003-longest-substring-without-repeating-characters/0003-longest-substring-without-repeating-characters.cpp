class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        set<char>st;
        int l = 0; int maxCnt = 0;
        for(int r =0; r<n; r++){
            while(st.find(s[r]) != st.end()){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxCnt = max(maxCnt, r-l+1);
        }
        return maxCnt;
    }
};
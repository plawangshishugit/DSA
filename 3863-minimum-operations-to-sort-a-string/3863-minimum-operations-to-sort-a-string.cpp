class Solution {
public:
    int minOperations(string s) {

        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if(s == t) return 0;

        if(n == 2) return -1;

        if(s[0] == t[0] || s[n-1] == t[n-1]){
            return 1;
        }

        return 2;
    }
};
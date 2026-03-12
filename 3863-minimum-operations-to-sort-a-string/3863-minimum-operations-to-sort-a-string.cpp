class Solution {
public:

    int minOperations(string s) {

        int n = s.size();
        string t = s;
        sort(t.begin(), t.end());

        if(t == s){
            return 0;
        }

        if(n == 2){
            return -1;
        }

        char mn = t[0];
        char mx = t[n-1];
        bool start = false;
        bool mid = false, end = false;
        for(int i = 0; i<n; i++){
            if(s[i] == mn){
                if(i== 0){
                    start = true;
                }
                else if(i != n-1){
                    mid = true;
                }
            }
            if(s[i] == mx){
                if(i == n-1){
                    end = true;
                }
                else if(i != 0){
                    mid = true;
                }
            }
        }
        if(start || end ){
            return 1;
        }
        if(mid ){
            return 2;
        }
        return 3;

    }
};
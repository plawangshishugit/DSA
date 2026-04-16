class Solution {
private:
    bool check(int i, string &h, string &n){
        for(int j = 0; j < n.size(); j++){
            if(h[i + j] != n[j]) return false;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i<= n-m; i++){
            if(haystack[i] == needle[0]){
                if(check(i,haystack,needle)){
                    return i;
                }
            }
        }
        return -1;
    }
};
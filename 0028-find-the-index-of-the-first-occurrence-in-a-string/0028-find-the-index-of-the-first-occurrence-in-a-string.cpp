class Solution {
private:
    bool check(int i, string haystack, string needle){
        int n = haystack.size();
        int m = needle.size();
        if(haystack.substr(i,m) == needle){
            return true;
        }
        else{
            return false;
        }
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
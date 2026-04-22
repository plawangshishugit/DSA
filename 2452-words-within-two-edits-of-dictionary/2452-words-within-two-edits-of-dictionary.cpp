class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int l = queries[0].size();
        int n = queries.size();
        int m = dictionary.size();
        vector<string>ans;
        for(int i =0; i<n; i++){
            bool isFound = false;
            for(int j =0; j<m; j++){
                int cnt = 0;
                for(int k =0; k<l; k++){
                    
                    if(queries[i][k] == dictionary[j][k]){
                        cnt += 1;
                    }
                }
                if(cnt + 2 >= l){
                    isFound = true;
                }
                if(isFound == true){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};
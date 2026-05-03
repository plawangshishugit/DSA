class Solution {
public:
    bool rotateString(string s, string goal) {
        string st = s+s;
        if(s.size() != goal.size()){
            return false;
        }
        if(st.find(goal) != -1){
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution {

public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l=0, r=0, us =0;
        for(int i =0; i<n; i++){
            if(moves[i] == 'R'){
                r+= 1;
            }
            if(moves[i] == 'L'){
                l+= 1;
            }
            if(moves[i] == '_'){
                us+= 1;
            }
        }
        return (abs(l-r) + us);
    }
};
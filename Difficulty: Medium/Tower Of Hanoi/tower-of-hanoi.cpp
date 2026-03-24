class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) return 0;

        int count = 0;

        // Step 1
        count += towerOfHanoi(n - 1, from, aux, to);

        // Step 2
        // cout << "Move disk " << n 
        //      << " from rod " << from 
        //      << " to rod " << to << endl;
        count++;

        // Step 3
        count += towerOfHanoi(n - 1, aux, to, from);

        return count;
    }
};
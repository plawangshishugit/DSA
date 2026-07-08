class Solution {
public:
    void printTillN(int n) {
        if (n == 1) {
            cout << 1 << " ";
            return;
        }

        printTillN(n - 1);
        cout << n << " ";
    }
};
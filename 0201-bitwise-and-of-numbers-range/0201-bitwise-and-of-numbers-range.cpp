class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

// What does x & (x-1) do?

// It removes the lowest set bit.

// Example:

// x     = 101100
// x - 1 = 101011
// ----------------
//         101000

// The rightmost 1 disappeared.
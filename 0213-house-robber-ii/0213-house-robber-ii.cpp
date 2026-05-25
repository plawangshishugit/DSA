class Solution {
private:
    // -----------------------------------------------------------------
    // HELPER FUNCTION: The standard House Robber solution (linear version)
    // -----------------------------------------------------------------
    // This is the same logic we developed in our previous problem Houe Robber 198.
    // It handles a linear street of houses (no circle).
    // I'll reuse it for both scenarios below.
    int robHelper(vector<int>& nums) {
        // BRAINSTORMING NOTE:
        // After solving the linear version, I realized this function is perfect
        // for any straight line of houses. I'll call it twice for the circle problem.
        
        if (nums.size() < 2)
            return nums[0];
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[nums.size() - 1];
    }

public:
    int rob(vector<int>& nums) {
        // -----------------------------------------------------------------
        // BRAINSTORMING JOURNEY: House Robber II (Circular Street)
        // -----------------------------------------------------------------
        
        // STEP 1: The "Aha! It's a circle!" moment
        // -----------------------------------------
        // I solved the linear version easily. But then the problem added:
        // "All houses are arranged in a CIRCLE. First and last are neighbors."
        // 
        // My initial reaction: "Oh no! Now house 0 and house n-1 are adjacent!
        //  My linear solution assumes they're not connected. What do I do?"
        
        // STEP 2: Trying a naive approach (that fails)
        // --------------------------------------------
        // First thought: "I'll just run my linear solution on the original array!"
        // But that doesn't work because it might rob both house 0 and house n-1.
        // For example: [2, 3, 2] -> Linear gives 3 (robbing house 1 only)
        // But if I think circular: robbing house 0 and house 2 is illegal!
        // So my linear solution might accidentally include both ends.
        
        // STEP 3: The key insight - Break the circle
        // ------------------------------------------
        // After 30 minutes of drawing circles on paper, I realized:
        // "In a circle, house 0 and house n-1 cannot BOTH be robbed."
        // 
        // This means there are only TWO possible scenarios:
        // Scenario A: I rob house 0. Then I CANNOT rob house n-1.
        //             So I consider houses [0, 1, 2, ..., n-2]
        // Scenario B: I rob house n-1. Then I CANNOT rob house 0.
        //             So I consider houses [1, 2, 3, ..., n-1]
        //
        // "Eureka! I've broken the circle into two linear problems!"
        
        // STEP 4: Edge case - What if there's only one house?
        // ---------------------------------------------------
        // If there's just one house in a circle, I can rob it.
        // My scenarios would create empty arrays. Better to handle this first.
        if (nums.size() == 0) {
            // No houses to rob
            return 0;
        }
        
        if (nums.size() == 1) {
            // Only one house in the circle. Easy choice - take it!
            return nums[0];
        }
        
        // STEP 5: Creating the two linear scenarios
        // -----------------------------------------
        // I need two separate arrays:
        // skipLastHouse: All houses EXCEPT the last one (indices 0 to n-2)
        // skipFirstHouse: All houses EXCEPT the first one (indices 1 to n-1)
        //
        // This feels like I'm splitting the circle into two different streets.
        // Let me visualize with [2, 3, 2, 5, 1]:
        // 
        // Original circle:   2 -- 3 -- 2 -- 5 -- 1 -- (back to 2)
        // 
        // Scenario A (skip last):  [2, 3, 2, 5]
        // Scenario B (skip first): [3, 2, 5, 1]
        //
        // Now I can use my trusted linear robHelper on each!
        
        // Create 2 new arrays
        vector<int> skipLastHouse(nums.size() - 1);
        vector<int> skipFirstHouse(nums.size() - 1);
        
        // STEP 6: Filling the arrays with a moment of realization
        // -------------------------------------------------------
        // As I write this loop, I realize: "I'm literally just copying elements."
        // skipLastHouse gets first n-1 houses (0 to n-2)
        // skipFirstHouse gets last n-1 houses (1 to n-1)
        // 
        // This is my "breaking the circle" moment made concrete in code.
        for (int i = 0; i < nums.size() - 1; i++) {
            skipLastHouse[i] = nums[i];        // Take from start
            skipFirstHouse[i] = nums[i + 1];   // Take from index 1 onwards
            
            // VISUALIZATION HELPER (in my mind):
            // When i = 0: skipLastHouse[0]=nums[0], skipFirstHouse[0]=nums[1]
            // When i = 1: skipLastHouse[1]=nums[1], skipFirstHouse[1]=nums[2]
            // ...
            // When i = n-2: skipLastHouse[n-2]=nums[n-2], skipFirstHouse[n-2]=nums[n-1]
        }
        
        // STEP 7: The divide and conquer moment
        // -------------------------------------
        // "Beautiful! Now I have two independent linear problems."
        // I'll solve each using my already-proven robHelper function.
        // This is like having two different streets to consider, and I'll pick
        // whichever yields more money.
        
        // Get the loot from both the possibilities
        int lootSkippingLast = robHelper(skipLastHouse);   // What if I exclude last house?
        int lootSkippingFirst = robHelper(skipFirstHouse); // What if I exclude first house?
        
        // STEP 8: Making the final decision
        // ---------------------------------
        // After both scenarios are calculated, I take the maximum.
        // This represents the best outcome considering the circular constraint.
        // 
        // DEEP THOUGHT:
        // "I didn't need to check the case where I skip BOTH ends because
        //  that's automatically considered in both scenarios. The optimal solution
        //  must either exclude house 0 OR exclude house n-1. There's no scenario
        //  where I include both, so I've covered all possibilities!"
        
        // Return the maximum of 2 loots
        return max(lootSkippingLast, lootSkippingFirst);
        
        // -----------------------------------------------------------------
        // POST-SOLUTION REFLECTION
        // -----------------------------------------------------------------
        // What I learned from this journey:
        // 
        // 1. "When constraints change, don't rewrite everything - adapt!"
        //    I reused my linear solution instead of starting from scratch.
        // 
        // 2. "Breaking a complex problem into smaller known problems is powerful."
        //    The circle problem became two linear problems.
        // 
        // 3. "Edge cases matter." The single house case almost broke my logic.
        // 
        // 4. "Space vs. Time tradeoff": I created two new arrays (O(n) space),
        //    but I could optimize by using index ranges without copying.
        //    However, for clarity, the copy approach is easier to understand.
        // 
        // Time Complexity: O(n) - I process each house twice (once per scenario)
        // Space Complexity: O(n) - I create two arrays of size n-1
        // 
        // Could I optimize space to O(1)? Yes! By passing start/end indices to
        // robHelper instead of creating new arrays. But that would complicate
        // the helper function. For now, this is clean and correct.
        // 
        // Final thought: "Sometimes the best way to handle a circle is to cut it."
    }
};
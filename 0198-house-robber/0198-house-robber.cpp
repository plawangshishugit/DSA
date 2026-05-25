class Solution {
public:
    int rob(vector<int>& nums) {
        
        // STEP 1: Understanding the problem
        // --------------------------------
        // "I cannot rob two adjacent houses because that would trigger the alarm."
        // Initially, I thought: "Okay, so I just pick every alternate house, right?"
        // But wait... what if the array is [2, 1, 1, 2]?
        // If I pick even indices: 2 + 1 = 3
        // If I pick odd indices: 1 + 2 = 3
        // But the optimal is 2 + 2 = 4 (houses 0 and 3)! They are not adjacent,
        // but they're also not strictly alternating. So my initial assumption was wrong.
        // I cannot simply pick all evens or all odds - I need to think dynamically!
        
        // STEP 2: Breaking it down - Thinking about the first house
        // ---------------------------------------------------------
        // Let me start small. If there's only 1 house [a], I take it. Easy.
        if (nums.size() < 2)
            return nums[0];
        
        // STEP 3: Two houses scenario
        // ---------------------------
        // If there are two houses [a, b], I take max(a, b).
        // Can't take both because they're adjacent. Makes sense.
        
        // STEP 4: Three houses - The "Aha!" moment
        // ----------------------------------------
        // For [a, b, c], what do I do?
        // Option 1: Take a + c (skip b)
        // Option 2: Take b (skip both a and c)
        // So answer = max(a + c, b)
        // But notice something: "a + c" = (best up to house 0) + current house
        // And "b" = best up to house 1
        // So for house at index i, the best is:
        // max(best up to i-2 + current, best up to i-1)
        
        // STEP 5: Realizing this is Dynamic Programming
        // ---------------------------------------------
        // "Ah! This is exactly like the Fibonacci sequence but with a max operation!"
        // At each house, I have a choice:
        // - ROB this house: then I MUST skip the previous house, so I take dp[i-2] + nums[i]
        // - SKIP this house: then I can keep whatever I had up to dp[i-1]
        // And I just take the maximum of these two choices.
        // This is the core insight that took me 20 minutes to see!
        
        // STEP 6: Optimization realization
        // --------------------------------
        // I don't actually need to store the entire dp array!
        // I only need the last two values: prev2 (i-2) and prev1 (i-1).
        
        // Create array to store the maximum loot at each index
        vector<int> dp(nums.size());
        
        // STEP 7: Base cases - Building from the ground up
        // ------------------------------------------------
        // For the first house, I have no choice. Take it.
        dp[0] = nums[0];
        
        // For the second house, I take the max of first and second.
        // Because I can only rob one of them (they are adjacent).
        dp[1] = max(nums[0], nums[1]);
        
        // STEP 8: The iterative realization
        // ---------------------------------
        // "I feel like I'm walking through the street, deciding house by house."
        // At each new house, I ask myself:
        // "Should I rob this one? If I do, I get its money plus what I had 2 houses ago.
        //  If I don't, I just keep what I had at the last house."
        // I take the better outcome. This greedy-but-backtracking approach works because
        // dp[i] always represents the best I can do up to house i.
        
        // Use them to fill complete array
        for (int i = 2; i < nums.size(); i++) {
            // STEP 9: The magic formula - Where it all comes together
            // -------------------------------------------------------
            // dp[i - 2] + nums[i] = Rob current house, add to best from two houses back
            // dp[i - 1] = Skip current house, keep best from previous house
            // I take the max because I want the most money possible.
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            
            // STEP 10: A moment of reflection
            // -------------------------------
            // "This is beautiful. Each decision only depends on the previous two results.
            //  I don't need to remember the entire history, just where I've been."
            // This is the essence of DP: breaking a complex problem into overlapping
            // subproblems and solving each one optimally.
        }
        
        // STEP 11: The final answer
        // -------------------------
        // After walking through all the houses (i from 0 to n-1),
        // dp[n-1] contains my optimal loot. I've considered all possibilities
        // without explicitly trying every combination (which would be 2^n!).
        
        // FINAL THOUGHT:
        // -------------
        // This problem taught me that sometimes the best solution isn't about
        // following a fixed pattern (like robbing every other house), but about
        // making optimal local decisions that lead to a global optimum.
        // It's like life: you can't take every opportunity, but you can choose
        // the combination that gives you the maximum value.
        
        return dp[nums.size() - 1];
        
        // EPILOGUE - Space Optimization I discovered later:
        // -------------------------------------------------
        // Instead of the dp array, I could write:
        // int prev2 = nums[0];
        // int prev1 = max(nums[0], nums[1]);
        // for (int i = 2; i < n; i++) {
        //     int current = max(prev2 + nums[i], prev1);
        //     prev2 = prev1;
        //     prev1 = current;
        // }
        // return prev1;
        // This uses O(1) space instead of O(n). But I kept the array version
        // because it's clearer for understanding the progression.
    }
};
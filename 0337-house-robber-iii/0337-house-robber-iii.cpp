/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // -----------------------------------------------------------------
    // HELPER FUNCTION: DFS traversal that returns [robThisNode, skipThisNode]
    // -----------------------------------------------------------------
    // This is where the magic happens. I'm returning TWO pieces of information
    // from each node: the best loot if I rob THIS node, and the best loot if I skip it.
    vector<int> travel(TreeNode* root) {
        // STEP 1: Base case - The leaf's children are null
        // ------------------------------------------------
        // When I reach a null node, there's no house to rob.
        // I return {0, 0} because:
        // - Robbing null gives 0
        // - Skipping null gives 0
        // This allows me to add values up the recursion tree.
        if (root == nullptr) {
            return {0, 0};  // {if I rob this null, if I skip this null}
        }
        
        // STEP 2: Post-order traversal - Go deep first
        // --------------------------------------------
        // "I need to know what my children are doing before I decide for myself."
        // This is the key insight: I traverse to the bottom of the tree first,
        // then make decisions on the way back up.
        // 
        // left_node_choices[0] = Best loot if I rob the LEFT child
        // left_node_choices[1] = Best loot if I skip the LEFT child
        vector<int> leftChoices = travel(root->left);
        
        // right_node_choices[0] = Best loot if I rob the RIGHT child
        // right_node_choices[1] = Best loot if I skip the RIGHT child
        vector<int> rightChoices = travel(root->right);
        
        // STEP 3: Prepare my own options array
        // ------------------------------------
        // options[0] = Best loot if I rob THIS node
        // options[1] = Best loot if I skip THIS node
        vector<int> options(2);
        
        // STEP 4: Case 1 - I rob the current node
        // ----------------------------------------
        // "If I rob this house, I CANNOT rob my immediate children."
        // So I take my value PLUS the best from my children when they are SKIPPED.
        // Because if I rob myself, my children must not be robbed.
        options[0] = root->val + leftChoices[1] + rightChoices[1];
        //                       ↑              ↑              ↑
        //                  my money + best if left skipped + best if right skipped
        
        // STEP 5: Case 2 - I skip the current node
        // -----------------------------------------
        // "If I skip this house, my children have a choice: they can be robbed OR skipped."
        // For each child, I take the MAXIMUM of robbing or skipping them.
        // Then I add those maximums together.
        options[1] = max(leftChoices[0], leftChoices[1]) + 
                     max(rightChoices[0], rightChoices[1]);
        //              ↑                              ↑
        //   best my left child can do (rob or skip) + best my right child can do (rob or skip)
        
        // STEP 6: Return my options to my parent
        // --------------------------------------
        // My parent will use these to decide whether to rob itself or not.
        return options;
    }

public:
    int rob(TreeNode* root) {
        // -----------------------------------------------------------------
        // BRAINSTORMING JOURNEY: House Robber III (Binary Tree)
        // -----------------------------------------------------------------
        
        // STEP 1: The tree realization
        // ----------------------------
        // "Now the houses are connected like a family tree!"
        // The rule is still the same: can't rob two adjacent houses.
        // But "adjacent" now means parent-child relationships in a binary tree.
        // 
        // My first thought: "I can't just do a simple DP array anymore.
        //  The structure is hierarchical, not linear."
        
        // STEP 2: Trying level-by-level approach (FAIL)
        // ---------------------------------------------
        // "Maybe I can rob all even levels vs odd levels?"
        // But that fails because within the same level, houses aren't connected,
        // but a grandparent and grandchild ARE connected through a skipped parent.
        // Example: Rob level 0 and level 2 might be allowed if level 1 is skipped.
        // Simple alternating levels doesn't capture all possibilities.
        
        // STEP 3: The "Eureka!" - Two-state DFS
        // -------------------------------------
        // After struggling for an hour, I realized:
        // "At each node, I only care about TWO possibilities:
        //  1. What's the max if I rob this node?
        //  2. What's the max if I skip this node?"
        // 
        // This is brilliant because:
        // - If I rob a node, my children must be skipped
        // - If I skip a node, my children can be either robbed or skipped (whichever is better)
        // 
        // And because of the tree structure, I can solve this with DFS!
        
        // STEP 4: Why return an array of 2?
        // --------------------------------
        // "I need to pass BOTH pieces of information up the tree."
        // My parent needs to know:
        // - What happens if I am robbed? (so it knows to skip me)
        // - What happens if I am skipped? (so it can consider robbing itself)
        // 
        // This is like my children whispering two numbers to me:
        // "Dad, if you rob me, you get X. If you skip me, you get Y."
        // Then I make my own decision based on their whispers.
        
        // STEP 5: The base case insight
        // ----------------------------
        // What about null nodes? They contribute 0 whether robbed or skipped.
        // So I return {0, 0} for null. This makes the recursion clean.
        
        // STEP 6: Putting it all together
        // ------------------------------
        // I call travel(root) which returns:
        // [best loot if I rob the root, best loot if I skip the root]
        // Then I take the maximum of these two!
        vector<int> result = travel(root);
        return max(result[0], result[1]);
        
        // STEP 7: Visualizing with an example
        // -----------------------------------
        // Let's trace through a simple tree:
        // 
        //       3
        //      / \
        //     2   3
        //      \   \
        //       3   1
        // 
        // At leaf (3, null, null):
        //   options[0] = 3 + 0 + 0 = 3
        //   options[1] = max(0,0) + max(0,0) = 0
        //   Return {3, 0}
        // 
        // At node 2 (left child of 3):
        //   left child (3) returns {3, 0}
        //   right child null returns {0, 0}
        //   options[0] = 2 + 0 + 0 = 2
        //   options[1] = max(3,0) + max(0,0) = 3 + 0 = 3
        //   Return {2, 3}
        // 
        // At node 3 (right child of root):
        //   right child (1) returns {1, 0}
        //   options[0] = 3 + 0 + 0 = 3
        //   options[1] = max(0,0) + max(1,0) = 0 + 1 = 1
        //   Return {3, 1}
        // 
        // At root (3):
        //   left returns {2, 3}, right returns {3, 1}
        //   options[0] = 3 + 3 + 1 = 7
        //   options[1] = max(2,3) + max(3,1) = 3 + 3 = 6
        //   Return {7, 6}
        // 
        // Final answer: max(7, 6) = 7
        // 
        // This makes sense! Robbing root (3) + left skipped (3) + right skipped (1) = 7
        
        // -----------------------------------------------------------------
        // POST-SOLUTION REFLECTION
        // -----------------------------------------------------------------
        // What I learned from this journey:
        // 
        // 1. "Tree DP is different from array DP."
        //    I can't use a linear approach. I need to traverse depth-first.
        // 
        // 2. "Sometimes you need to return multiple values from recursion."
        //    Returning a single number isn't enough. I need to return both
        //    "robbed" and "skipped" states to my parent.
        // 
        // 3. "The tree structure naturally leads to post-order traversal."
        //    I need my children's answers before I can answer for myself.
        // 
        // 4. "Think about what information each node needs from its children."
        //    This is the essence of tree DP: define the state that flows upward.
        // 
        // 5. "This problem is like the linear version, but on a tree."
        //    In linear version: dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        //    In tree version: if rob node = node.val + skip(children)
        //                    if skip node = max(rob or skip for each child)
        // 
        // Time Complexity: O(n) - I visit each node exactly once
        // Space Complexity: O(h) - recursion stack depth = height of tree
        // 
        // Final thought: "The house robber trilogy taught me that the same
        //  constraint (no adjacent houses) leads to completely different solutions
        //  based on the data structure: array, circle, or tree. Beautiful!"
    }
};
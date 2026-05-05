/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        vector<int> temp;
        ListNode* curr = head;

        // Step 1: store values
        while (curr != nullptr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int n = temp.size();
        k = k % n;

        // Step 2: rotate (right rotation)
        vector<int> rotated(n);
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = temp[i];
        }

        // Step 3: create new linked list
        ListNode* newHead = new ListNode(rotated[0]);
        curr = newHead;

        for (int i = 1; i < n; i++) {
            curr->next = new ListNode(rotated[i]);
            curr = curr->next;
        }

        return newHead;
    }
};
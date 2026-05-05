class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;

        vector<int> temp;
        ListNode* curr = head;

        // store values
        while (curr != nullptr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int n = temp.size();
        k = k % n;

        // build new list using rotated indexing
        ListNode* newHead = new ListNode(temp[(0 - k + n) % n]);
        curr = newHead;

        for (int i = 1; i < n; i++) {
            curr->next = new ListNode(temp[(i - k + n) % n]);
            curr = curr->next;
        }

        return newHead;
    }
};
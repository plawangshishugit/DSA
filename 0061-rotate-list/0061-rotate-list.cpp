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

        // Step 2: overwrite values in original list
        curr = head;
        for (int i = 0; i < n; i++) {
            curr->val = temp[(i - k + n) % n];
            curr = curr->next;
        }

        return head;
    }
};
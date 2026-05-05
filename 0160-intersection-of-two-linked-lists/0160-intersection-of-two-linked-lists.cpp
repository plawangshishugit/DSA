/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;

        // Add all nodes of list A
        for (ListNode* cur = headA; cur != nullptr; cur = cur->next) {
            seen.insert(cur);
        }

        // Check nodes of list B
        for (ListNode* cur = headB; cur != nullptr; cur = cur->next) {
            if (seen.count(cur)) {
                return cur; // intersection found
            }
        }

        return nullptr; // no intersection
    }
};
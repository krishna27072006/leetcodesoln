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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        for (ListNode* head : lists) {
            while (head) {
                values.push_back(head->val);
                head = head->next;
            }
        }

        if (values.empty()) return NULL;

        sort(values.begin(), values.end());

        ListNode* head = new ListNode(values[0]);
        ListNode* curr = head;

        for (int i = 1; i < values.size(); i++) {
            curr->next = new ListNode(values[i]);
            curr = curr->next;
        }

        return head;
    }
};

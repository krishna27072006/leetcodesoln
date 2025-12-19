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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        int sum = 0;

        while (temp) {
            if (temp->val != 0) {
                sum += temp->val;
            } else {
                if (sum != 0) {
                    v.push_back(sum);
                    sum = 0;
                }
            }
            temp = temp->next;
        }

        ListNode* ans = new ListNode(v[0]);
        ListNode* pre = ans;

        for (int i = 1; i < v.size(); ++i) {
            ListNode* node = new ListNode(v[i]);
            pre->next = node;  
            pre = node;
        }

        return ans;
    }
};

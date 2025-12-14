/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> v;
        ListNode* temp = head;

        while (temp) {
            if (find(v.begin(), v.end(), temp) != v.end()) {
                return true;  // cycle found
            }
            v.push_back(temp);
            temp = temp->next; // move forward
        }
        return false;
    }
};

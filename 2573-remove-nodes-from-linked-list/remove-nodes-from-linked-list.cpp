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
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);      // Step 1: reverse the list
        ListNode* temp = head;
        int maxi = temp->val;          // first node is always kept

        while(temp != nullptr && temp->next != nullptr) {
            if(temp->next->val < maxi) {
                // remove next node
                temp->next = temp->next->next;
            } else {
                // update maxi and move forward
                maxi = temp->next->val;
                temp = temp->next;
            }
        }

        head = reverseList(head);      // Step 3: reverse back
        return head;
    }

private:
    // Helper function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

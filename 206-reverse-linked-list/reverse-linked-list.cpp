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
    ListNode* f(ListNode*curr,ListNode*prev){
        if(curr==NULL){
            return prev;
        }
        ListNode* front = curr->next;
        curr->next=prev;
        return f(front,curr);
    }
    
    ListNode* reverseList(ListNode* head) {
        return f(head,NULL);
    }
};
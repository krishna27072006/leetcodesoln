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
        if (head == NULL || head->next == NULL) return head;
        ListNode* dummy=new ListNode(0,head);
        ListNode* fast=dummy;
        ListNode* slow=dummy;
        int len=1;
        ListNode* cur=head;
        while(cur->next!=NULL){
            len++;
            cur=cur->next;
        }
        k=k%len;
        if(k==0) return head;
        for(int i=0;i<k;++i){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=head;
        ListNode*ans=slow->next;
        slow->next=NULL;
        return ans;
    }
};
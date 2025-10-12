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
    ListNode* deleteMiddle(ListNode* head) {
        int ct=0;
        ListNode*temp=head;
        while(temp){
            ct++;
            temp=temp->next;
        }
        if(ct==1)return NULL;
        ListNode*ans=head;
        int t=0;
        int k=(ct/2)+1;
        while(ans){
            t++;
            if(t==k-1){
            ans->next=ans->next->next;
            break;
            }
        ans=ans->next;
        }
        return head;
        
    }
};
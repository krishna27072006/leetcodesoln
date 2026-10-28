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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL) return list1;
        ListNode* l1=list1;
        ListNode* l2=list2;
        if(l1->val>l2->val){
            swap(l1,l2);
        }
        ListNode* res=l1;
        while(l1!=NULL && l2!=NULL){
            ListNode* temp=NULL;
             while(l1!=NULL && l1->val<=l2->val){
                  temp=l1;
                  l1=l1->next;
             }
             if (temp != NULL) {
                temp->next = l2;
            }

             swap(l1,l2);

        }
        return res;
    }    
    ListNode* f(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rightHead = slow->next;
        slow->next = NULL; 

        ListNode* left=f(head);
        ListNode* right=f(rightHead);

        return mergeTwoLists(left,right);

    }
    ListNode* sortList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        return f(head);
    }
};
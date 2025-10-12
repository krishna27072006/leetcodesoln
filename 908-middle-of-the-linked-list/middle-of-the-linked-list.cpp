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
    ListNode* middleNode(ListNode* head) {
        int ct=0;
        ListNode*temp=head;
        while(temp){
            ct++;
            temp=temp->next;
        }
        ListNode*ans=head;
        int t=0;
        int k=(ct/2)+1;
        while(ans){
            t++;
            if(t==k){
            break;
            }
        ans=ans->next;
        }
        return ans;

    }
};
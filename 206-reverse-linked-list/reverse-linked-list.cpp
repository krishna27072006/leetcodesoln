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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        ListNode*temp=head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        if(v.empty()) return nullptr;
        reverse(v.begin(),v.end());
        ListNode*head1=new ListNode(v[0]);
        ListNode*mover=head1;
        for(int i=1;i<v.size();++i){
            ListNode*x=new ListNode(v[i]);
            mover->next=x;
            mover=x;
        }
        return head1;
        
    }
};
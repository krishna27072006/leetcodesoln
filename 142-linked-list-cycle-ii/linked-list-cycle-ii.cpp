/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<ListNode*> v;
        ListNode*temp=head;
        while(temp){
            if(find(v.begin(), v.end(), temp) != v.end()){
                return temp;
                break;
            }
            v.push_back(temp);
            temp=temp->next;
        }
        return nullptr;
    }
};
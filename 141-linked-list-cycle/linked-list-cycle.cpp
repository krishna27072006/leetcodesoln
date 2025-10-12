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
    bool hasCycle(ListNode *head) {
        bool ans=false;
        vector<ListNode*> v;
        ListNode*temp=head;
        while(temp){
            if(find(v.begin(), v.end(), temp) != v.end()){
                ans=true;
                break;
            }
            v.push_back(temp);
            temp=temp->next;

        }
        return ans;
        
    }
};
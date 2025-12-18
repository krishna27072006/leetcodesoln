class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> v1;
        vector<ListNode*> v2;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1){
            v1.push_back(temp1);
            temp1 = temp1->next;
        }

        while(temp2){
            v2.push_back(temp2);  // ✅ FIXED
            temp2 = temp2->next;
        }

        for(int i = 0; i < v1.size(); i++){
            for(int j = 0; j < v2.size(); j++){
                if(v1[i] == v2[j]){
                    return v1[i]; // return immediately
                }
            }
        }
        return NULL;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* head2 = head->next;
        ListNode* temp = head->next->next;
        ListNode* prev1 = head;
        ListNode* prev2 = head2;
        int ct = 3;

        while(temp != NULL){
            ListNode* nextNode = temp->next;

            if(ct % 2 != 0){
                prev1->next = temp;
                prev1 = temp;
            }else{
                prev2->next = temp;
                prev2 = temp;
            }

            ct++;
            temp = nextNode;
        }

        prev2->next = NULL;
        prev1->next = head2;

        return head;
    }
};
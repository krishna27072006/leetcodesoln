class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int ct = 0;
        while (temp) {
            ct++;
            temp = temp->next;
        }

        int ct2 = 0;
        int k = ct - n;
        ListNode* pre = nullptr;
        ListNode* temp1 = head;

       
        if (k == 0) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        while (temp1) {
            if (ct2 == k - 1) {                 
                temp1->next = temp1->next->next; 
                break;
            }
            ct2++;
            temp1 = temp1->next;               
        }
        return head;
    }
};

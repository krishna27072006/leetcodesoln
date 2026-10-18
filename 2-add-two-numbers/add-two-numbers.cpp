
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;

        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int v1 = 0;
            int v2 = 0;

            if (l1 != NULL) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int value = v1 + v2 + carry;

            ListNode* add = new ListNode(value % 10);
            temp->next = add;

            carry = value / 10;
            temp = temp->next;
        }

        return head->next;
    }
};

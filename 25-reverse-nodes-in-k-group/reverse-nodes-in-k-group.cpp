
class Solution {
public:
    ListNode* f(ListNode* curr, ListNode* prev, int ct, int k,
                ListNode*& temp) {
        if (ct == k) {
            temp = curr;
            return prev;
        }

        ListNode* front = curr->next;
        curr->next = prev;

        return f(front, curr, ct + 1, k, temp);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) {
            return head;
        }

        ListNode* temp = head;
        ListNode* ans = NULL;
        ListNode* tail = NULL;

        while (temp != NULL) {
            ListNode* check = temp;
            int count = 0;

            while (check != NULL && count < k) {
                check = check->next;
                count++;
            }

            if (count < k) {
                if (tail != NULL) {
                    tail->next = temp;
                }
                break;
            }

            ListNode* last = temp;
            ListNode* first = f(temp, NULL, 0, k, temp);

            if (ans == NULL) {
                ans = first;
            }

            if (tail != NULL) {
                tail->next = first;
            }

            tail = last;
        }

        return ans;
    }
};

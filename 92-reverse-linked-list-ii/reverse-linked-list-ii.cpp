class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> v;
        ListNode* temp = head;

        while (temp) {
            v.push_back(temp->val);
            temp = temp->next;
        }

        // Fix: 1-based to 0-based
        left--;
        right--;

        while (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
        }

        // Rebuild linked list
        ListNode* head1 = new ListNode(v[0]);
        ListNode* temp1 = head1;

        for (int i = 1; i < v.size(); i++) {
            temp1->next = new ListNode(v[i]);
            temp1 = temp1->next;
        }

        return head1;
    }
};

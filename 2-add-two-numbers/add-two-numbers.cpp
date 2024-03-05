class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = nullptr; // Result list
        ListNode* head = nullptr; // Head of the result list
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Calculate the sum of current digits and the carry
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10; // Update carry

            // Create a new node for the sum digit
            ListNode* newNode = new ListNode(sum % 10);

            // Append the new node to the result list
            if (l3 == nullptr) {
                l3 = newNode;
                head = l3;
            } else {
                l3->next = newNode;
                l3 = l3->next;
            }
        }

        return head;
    }
};

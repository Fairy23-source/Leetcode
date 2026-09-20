class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Empty list or single node
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Find length and tail
        int n = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }

        // Remove unnecessary rotations
        k = k % n;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Find new tail
        int steps = n - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};
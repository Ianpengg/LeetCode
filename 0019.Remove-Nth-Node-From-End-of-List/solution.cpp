

// TC: O(n)  SC: O(1
// Optimal solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *tmp;
        ListNode dummy(0);
        tmp = &dummy;
        tmp ->next = head;
        fast = tmp;
        slow = tmp;
        for (int i = 0; i < n; i++) {
          fast = fast->next;
        }

        while (fast->next != NULL) {
          fast = fast->next;
          slow = slow->next;
        }
        ListNode *tmp3 = slow->next;
        slow->next = slow->next->next;
        delete tmp3;
        
        return dummy.next;

    }    
};
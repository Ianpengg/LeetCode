// TC: O(n)  SC: O(1)
// Not the best ->some edge case check can be removed by adding the dummmy node;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head, *tmp, *tmp2;
        int cnt = 0;
        if (head->next == NULL) return NULL;
        while (cnt < n) {
          fast = fast->next;
          cnt++;
        }
        while (fast != NULL) {
          tmp = slow;
          fast = fast->next;
          slow = slow->next;
        }
        tmp2=slow->next;
        if (slow == head) {
          head = head->next;
          return head;
        }
        tmp->next = tmp2;
        return head;
    }    
};

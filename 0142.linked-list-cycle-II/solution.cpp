
// TC: O(n), SC: O(1)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
      ListNode *fast = head, *slow = head;
      int flag = 0;
      if (!head || !head->next) return NULL;
      while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
          flag = 1;
          break;
        }
      }
      if (flag != 1) return NULL;
    
      while(head != slow) {
        head = head->next;
        slow = slow->next;
      }
      return head;
    };
};
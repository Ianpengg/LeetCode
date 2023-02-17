
// TC: O(left+right), SC: O(1)
// Strian forward method 
// Split the original list into 3 parts: left, middle, right
// Reverse the middle part
// Connect the 3 parts together
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        ListNode *init = &dummy;
        ListNode *left_h, *right_h;
        init->next = head;
        ListNode *cur = init;
        for (int i =0; i < right; i++)
          cur = cur->next;
        ListNode *c = cur->next;
        cur->next = NULL;

        cur = init;
        for (int i = 0; i < left-1; i++) 
          cur = cur->next;
        ListNode *b = cur->next;
        cur->next = NULL;
        
        b = reverseList(b);

        cur = init;
        while (cur->next) cur = cur->next;
        cur->next = b;
        while (cur->next) cur = cur->next;
        cur->next = c;

        return dummy.next;      
    }
private:
  ListNode* reverseList(ListNode *head) {
    ListNode *cur, *prev = NULL, *tmp;
    cur = head;
    while (cur) {
      tmp = cur->next;
      cur->next = prev;
      prev = cur;
      cur = tmp;
    }
    return prev;
  }
};

//TC: O(n) , SC: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode dummy(0);
      ListNode *tail = &dummy;
      while (list1 && list2) {
        if (list1->val >= list2->val) {
          tail->next = list2;
          list2 = list2->next;
        }
        else {
          tail->next = list1;
          list1 = list1->next;
        }
        tail = tail->next;
      } 
      while (list1) {
        tail->next = list1;
        list1 = list1->next;
        tail = tail->next;
      }
      while (list2) {
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
      }
      return dummy.next;      
    }
};
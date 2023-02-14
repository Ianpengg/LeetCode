/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// Time Complexity O(nlogn) Space Complexity O(logn)
// mrege is O(n) and sort is O(logn) so total time complexity is O(nlogn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {
      // If List contain a single or 0 node
      if (head == NULL || head->next == NULL) return head;

      ListNode *temp = NULL;
      ListNode *slow = head;
      ListNode *fast = head;

      // use 2 pointer fast + slow to find the center node of the list
      while (fast != NULL && fast -> next != NULL) {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
      }
      // end of first left half
      temp->next = NULL;
      
      ListNode *l1 = sortList(head);  //left half recursive call
      ListNode *l2 = sortList(slow);  //right half recursive call 

      return mergelist(l1, l2); //mergelist Function call

    }

private:
  ListNode *mergelist(ListNode *l1, ListNode *l2) {
      ListNode dummy(0);
      ListNode *tail = &dummy;
      //check the two list are not empty
      while (l1 && l2) {
        if (l1->val > l2->val) swap(l1, l2);
        tail->next = l1;
        l1 = l1->next;
        tail = tail->next;
      }
      if (l1) tail->next = l1;
      if (l2) tail->next = l2;
      return dummy.next;
    }
};
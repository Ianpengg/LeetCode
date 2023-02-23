

// TC: O(max(m,n)) SC: O(max(m,n))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;

        ListNode *head1=l1, *head2=l2, *prev=NULL; 
        while (head1 != NULL && head2 != NULL ) {
          sum = head1->val + head2->val + carry;
          carry = sum/10;
          head1->val = sum%10;
          prev = head1;
          head1 = head1->next;
          head2 = head2->next;
        }
        while (head1 != NULL) {
          sum = head1->val + carry;
          carry = sum / 10;
          head1->val = sum%10;
          prev = head1;
          head1 = head1->next;
        }
        while (head2 != NULL) {
          sum = head2->val + carry;
          carry = sum / 10;
          prev->next = new ListNode(sum % 10);
          prev = prev->next;
          head2 = head2->next;
        }     
        if (carry > 0) {
          prev->next = new ListNode(carry);
        }
        
        return l1;
    } 
};

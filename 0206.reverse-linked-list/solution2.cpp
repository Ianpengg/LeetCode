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
// Time complexity : O(n) Space complexity : O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *temp, *prev=NULL, *cur=head;

        while (cur) {
           temp = cur->next;
           cur->next = prev;
           prev = cur;
           cur = temp;
        }
        return prev;
    }
};
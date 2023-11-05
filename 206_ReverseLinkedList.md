
Space Complexity : O(1)
Time Complexity : O(N)

這題有分兩種解法, 遞迴解跟迭代解, 迭代解的概念比較簡單, 利用總共三個指針來對元素進行操作, 我們的目標是要慢慢的將鏈表從前面反轉  
先把curr->next的節點暫存在temp之後 curr->next指向prev, 此時我們已經反轉了node的指向,   接下來就把curr跟prev往下一個節點移動再重複之前的步驟一直到curr==NULL就完成鏈表的反轉了  

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* curr = head;

      while (curr != NULL) {
          ListNode* temp_next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp_next;
      }
      return prev;
    }
};
```

Recursive version:

Space Complexity : O(N)
Time Complexity : O(N)

遞迴解的核心在於每一次函數執行都做了些什麼,  
首先我們可以畫出執行完reverseList(head->next)函數時的狀態  
ex: original:  1 -> 2 -> 3 -> 4 -> 5  
               1 -> 2 <- 3 <- 4 <- 5   
              head null           last  
最後會發現我們需要做   
`head->next->next = head`  
`head->next = NULL`  
讓List變成 NULL <- 1 <- 2 <- 3 <- 4 <- 5  
最後return last也就是 5 來得到反轉後的鏈表  

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next==NULL) return head;
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};
```

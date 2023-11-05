
Space Complexity : O(1)
Time Complexity : O(N)

先創立一個dummy node來處理邊界問題, 並且透過比較兩個list的節點大小來分別加入到dummy node的後面  
由於list長度可能不一樣因此我們在第一個循環結束後還需要分別確認兩個list是不是到尾巴了, 如果還有元素沒加入的話則全部加進dummy node後面。

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

       ListNode dummy(0);
       ListNode* tmp = &dummy;

        while (list1 && list2 ) {
            if (list1->val <= list2->val) {
                tmp->next = list1;
                list1 = list1->next;
               
            } else {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;

        }

        //check the remaining 
        while (list1 != NULL) {
            tmp->next = list1;
            tmp = tmp->next;
            list1 = list1->next;
        }
        while (list2 != NULL) {
            tmp->next = list2;
            tmp = tmp->next;
            list2 = list2->next;
        }
        return dummy.next;
    }
};
```

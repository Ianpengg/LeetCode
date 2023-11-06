
Space Complexity : O(1)
Time Complexity : O(N)

這題要設計一個可以執行getMin()函數來取得stack中最小值的stack結構  
我們可以很簡單的利用一個輔助的stack來儲存每次push值進入stack時當下的最小值  
ex： 
stack中 1, 3, 2, 5, -1  
min_stack中則是 1, 1, 1, 1, -1  
則我們在直接getMin()時只要返回min_stack的頂層元素就好  
並且在對stack進行pop()操作時, 要同時把min_stack中的元素也pop出來  


```c++
class MinStack {
public:
    stack<int> s;
    stack<int> s_min;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if (s_min.empty()) {
            s_min.push(val);
        } else {
            if (val < s_min.top()) {
                s_min.push(val);
            } else {
                s_min.push(s_min.top());
            }
        }
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
            s_min.pop();
        } 
    }
    
    int top() {
        if (!s.empty()) {
            return s.top();
        }
        return -1;
    }
    
    int getMin() {
        return s_min.top();
    }
};

```

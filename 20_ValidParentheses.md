
Space Complexity : O(n)
Time Complexity : O(n)

這題會用到一個技巧就是：我們在看到左側的括號之後如果沒有馬上接上另一個對稱的右側括號, 則我們就知道這是不合規則的  
因此可以利用先進後出的stack資料結構來處理, 只要是左側的括號就通通壓入, 並且我們可以在遇到右側括號時先判斷stack頂的元素, 是否是對應的左括號  
如果是的話就可以將其彈出stack, 我們可以重複這個步驟直到遇到不對稱的右側括號或者說到最後stack中只剩下左側括號就返回false,  
如果最後stack是空的則代表全部的括號都配對成功則返回true

```c++
class Solution {
public:
    bool isValid(string s) {
       stack<char> t;
       for (char c : s) {
           if (c == '(' || c == '[' || c == '{') {
                t.push(c);
           } else {
                if (!t.empty() && convert(c) == t.top())
                    t.pop();
                else 
                    return false;
           }
       }

       return t.empty();
    }
    // use to map the right parentherses to left one
    char convert(char c) {
        if (c == '}') return '{';
        if (c == ']') return '[';
        return '(';
    }
};

```

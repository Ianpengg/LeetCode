
Space Complexity : O(n)
Time Complexity : O(n)

首先利用 isalnum() 跟 tolower() 把輸入字串過濾掉非數字及字母的字元並將大寫轉成小寫  
由於回文是對稱的結構, 因此可以用雙指針的方法來處裡, 設置left跟right指針依序往中間移動, 並在每次移動之後判斷兩邊指到的字符是否相等  


```c++
class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for (char ch:s) {
            if (isalnum(ch)){
              res += tolower(ch);
            }
        }
        
        int left = 0, right = res.length() - 1;

        while (left < right ) {
          if (res[left] != res[right]) {
            return false;
          }
          left++; 
          right--;
        }
        return true;
    }
};

```

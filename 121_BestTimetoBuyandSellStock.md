
Space Complexity : O(1)
Time Complexity : O(N)

這題有個技巧, 我們可以維護一個minVal來記錄當下的最小值為何  
並且對於每一天都計算當天的價格減去最小值的結果, 也就是我們希望求得的獲利  
後續我們只要不斷更新我們的獲利, 讓最後獲利的值為最大就好  
而且可以這樣做是因為我們只會買進一次跟賣出一次, 因此我們可以確定最小值一定會比最大值先出現  
如果可以多次買進跟賣出則會需要更複雜的解法ex: 動態規劃... 等  


```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minVal = INT_MAX, temp = 0;
       for (auto num : prices) {
           minVal = min(minVal, num);
           temp = max(temp, num - minVal);
       }
       return temp;
    }
}
```


Space Complexity : O(1)
Time Complexity : O(n)

這題一樣用 two pointers技巧, 從數組前後開始用雙指針搜尋, 每次找出左右最低的數值, 並往內縮  
這邊從最低的數值開始往內縮是因為最大的容量取決於左右最低的那邊, 而從最低的那側往內縮才有機會遇到更大的值  


```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxval = 0;
        while (left < right) {
            int min_h  = min(height[left], height[right]);
            maxval = max(maxval, min_h * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        } 
        return maxval;
    }
};

```

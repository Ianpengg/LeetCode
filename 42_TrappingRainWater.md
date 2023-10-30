
Space Complexity : O(n)
Time Complexity : O(n)

這題比較複雜, 主要重點會是如何計算每一個height能裝的水, 最基本的規則是每一格能裝的水會受到左右高度的影響  
而每格能裝的水會等於 min(left_max, rightmax) - height[i], 因此我們可以建立一個vector來儲存每一格對應的left max跟 right max  
之後我們就可以算出每一格height對應的min(left_max, rightmax) 如此一來就可以取得每一格能儲存的水量了。

有另個解法是利用雙指針, 能將space complexity優化到O(1) 有空會補看看～



```c++
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> min_lr(height.size());
        // get the left max for each height
        int temp_l = 0;
        for (int i = 0; i < height.size(); i++) {
            temp_l = max(temp_l, height[i]);
            min_lr[i] = temp_l;
        }

        temp_l = 0;
        // I combined the get the right max and min(leftmax, rightmax) into one loop
        for (int i = height.size() - 1; i > 0; i--) {
            temp_l = max(temp_l, height[i]);
            min_lr[i] = min(min_lr[i], temp_l);
        }
        
        int res = 0;
        
        for (int i = 0; i < height.size(); i++) {
            if (min_lr[i] < height[i]) 
                continue;
            else 
                res += min_lr[i] - height[i];
        }
        return res;
    }
};

```

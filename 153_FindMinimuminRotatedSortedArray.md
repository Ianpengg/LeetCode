
Space Complexity : O(1)
Time Complexity : O(log(M * N))

這題的話題目有兩個提示, 1.對於每一列都是由小到大排序的 2.每一列的最後一個元素都會小於下一列的第一個元素
因此我們可以發現 我們能夠先對row做一次二分查找 找出target可能在的row  
接著我們再對 col做一次二分查找就可以將時間複雜度控制在 O(logM + logN) = O(log(M * N))  

第二種解法是 直接將二維矩陣利用矩陣大小來將他展開成一維陣列, 如此就能夠直接套用一般一維陣列的二分查找算法了


```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(); 
        int left = 0, right = n*m-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid / m][mid % m] == target) {
                return true;
            }
            else if (matrix[mid / m][mid % m] < target) {
                left = mid + 1;
            } 
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};
```

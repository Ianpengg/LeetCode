
Space Complexity : O(1)
Time Complexity : O(n)

首先 暴力解方法就是直接跑兩個nest for loop將nums中元素相乘除了i = j的那個元素-Time Complexity O(n^2)  
這種連乘的題目可以聯想到prefix sum的方式, 首先從左側做prefix multiplication, 之後再從右側做suffix multiplication  
ex: nums = [1, 2, 3, 4], prefix = [1, 2, 6, 24], suffix = [24, 24, 12, 4]  
然後我們就可以發現當去除當下元素並取得其他元素相乘的答案時, 其實就是將當下元素左邊的prefix multiplication結果乘上當下元素右邊的suffix multiplication結果  
ex : nums = [1, 2, 3, "4", 5, 6]  那4以外的相乘 就是 $(1 * 2 * 3)$ * $(6*5)$ 

因此可以跑兩個for loop來達成, 這邊用到一個技巧, 第一次loop結果要存的是每個元素的左側的prefix值, 並且在第二次loop將每個元素右側的suffix值直接乘上第一次的結果  
ex: nums = [1, 2, 3, 4]  我們的prefix 會變成 [1, 1, 2, 6] suffix 會是 [24, 12, 4, 1]  
這樣我們才能直接將每個元素乘上他右側的suffix值求出結果 達到Time Complexity:O(n)  

```c++

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        int sum = 1;

        // store the prefix 
        for (int i = 0; i < n; i++) {
            res[i] *= sum;
            sum *= nums[i];
        }

        int temp = 1;
        
        for (int i = n-1; i>=0; i--) {
            res[i] *= temp;
            temp *= nums[i];
        }
        return res;
    }
};

```

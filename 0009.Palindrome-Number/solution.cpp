// TC: O(log_10(x))   SC: O(1)


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int sum = 0, temp_x = x; 
        long long int power=10;
        while (temp_x > 0) {
          sum = power *sum + (temp_x % 10);
          temp_x = temp_x / 10;
        }
        if (sum == x) {
          return true;
        } 
        return false;
    }
};


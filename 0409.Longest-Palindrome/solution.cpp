
// TC:O(n) SC:O(1)


class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        vector<int> freq(128, 0);
        for (const char c: s) {
            ++freq[c];
        }
        int odd = 0;
        for (const int &fre : freq) {
            ans += (fre % 2 ==0) ? fre : fre-1;

            if (fre % 2 !=0)
                odd = 1;
        } 
        ans += odd;
        return ans;

    }
};


//TC: O(n) SC: O(1)

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // use double pointer
        if (arr.size() < 3) return false;
        int n = arr.size();
        int i = 0;

        for (; i < n-1; i++) {
          if (arr[i] > arr[i+1]) {
            i++;
            break;
          } 
          else if (arr[i] == arr[i+1]) {
            return false;
          }
        }

        if (i < 2 ) return false;
        for (; i < n; i++) {
          if (arr[i-1] <= arr[i]) {
            return false;
          }
        }
        return true;
        

    }
};
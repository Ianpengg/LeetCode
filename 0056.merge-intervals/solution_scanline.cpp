



// Scan line algorithmn
// Time complexity: O(nlogn)  ->sort algorithmn
// Space complexity: O(n)  -> diff vector

class Solution {
  static bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first)
      return a.first < b.first;
    else
      return a.second > b.second;
  }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> diff;  //{timestamp, +1/-1}
        // store the start and end of sub interval into an vector and assign +1/-1 with them
        for (auto &interval: intervals) {
          diff.push_back({interval[0], 1});
          diff.push_back({interval[1], -1});
        }
        // sort the diff according to custom cmp function 
        // note: first compare timestamp, second if timestamp the same, take +1 first
        sort(diff.begin(), diff.end(), cmp);
        vector<vector<int>> ans;
        int sum = 0;
        int start, end;
        for (int i = 0; i<diff.size(); i++) {
          // record the instant change from 0 -> 1
          if (sum == 0 && sum + diff[i].second == 1) {
            start = diff[i].first;
          }
          // record the instant change from positive integer -> 0
          else if (sum > 0 && sum + diff[i].second == 0) {
            end = diff[i].first;
            ans.push_back({start, end});
          }
          sum += diff[i].second;
        }
        return ans;
    }
};
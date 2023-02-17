
// TC: O(nlogn), SC: O(1) because the answer is not counted in space complexity

// Idea , First store the interval into answer and compare the next interval's start with the interval 
// already in the answer. If the start is smaller than the end of the interval in the answer, then merge
// the current interval into existed one
// ex 1. [1,3], 2. [2,6] ->  2 < 3, replace the [1, 3] with [1, 6] 
// ex 1. [1, 4], 2. [5, 7] -> 5 > 4, so directly push the interval [5,7] into the answer

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> output;
        for(auto interval : intervals){
            if(output.empty() || output.back()[1] < interval[0]){
                output.push_back(interval);
            }
            else{
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }
        return output;
    }

};
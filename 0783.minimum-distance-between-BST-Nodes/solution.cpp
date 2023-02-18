

// TC: O(n)  SC: O(h)
// Use in order traversal to traverse the tree

class Solution {
    
public:
    int minDiffInBST(TreeNode* root) {
      int prev = -1;
      int min_diff = INT_MAX;
      if (root == NULL) return -1;
      helper(root, prev, min_diff);

      return min_diff;
    }
private:
    void helper(TreeNode *root, int &prev, int &min_diff) {
      if (root == NULL) return;

      helper(root->left, prev, min_diff);
      if (prev != -1) {
        min_diff = min(min_diff, abs(root->val - (prev)));
      }
      prev = root->val;
      helper(root->right, prev, min_diff);
    }
};
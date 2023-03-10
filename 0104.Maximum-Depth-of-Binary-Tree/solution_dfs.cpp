
// TC: O(n)  SC: O(n)

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }

      return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
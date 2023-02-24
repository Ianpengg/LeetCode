
// TC: O(n)  SC: O(n)

class Solution {
  vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // if (root == NULL) return ans;
        if (root != NULL) {
          inorderTraversal(root->left);
          ans.push_back(root->val);
          inorderTraversal(root->right);
        }
        return ans;
    }
};
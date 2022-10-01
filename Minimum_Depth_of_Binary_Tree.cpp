class Solution {
public:
    int minDepth(TreeNode* root) {
  if (!root) return 0;

  queue<TreeNode*> q;
  q.push(root);
  int depth = 1;

  while (!q.empty()) {
    int level_size = q.size();
    for (int i = 0; i < level_size; i++) {
      TreeNode* curr_node = q.front();
      q.pop();
      if (!curr_node->left && !curr_node->right)
        return depth;  // first leaf we reach

      if (curr_node->left) q.push(curr_node->left);
      if (curr_node->right) q.push(curr_node->right);
    }

    depth++;
  }

  return depth;
    }
};

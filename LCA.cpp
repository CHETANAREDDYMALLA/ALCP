#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }
    TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);
    if (leftResult != nullptr && rightResult != nullptr) {
        return root;
    }
    return (leftResult != nullptr) ? leftResult : rightResult;
}
int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    TreeNode* p = root->left;     // Node 5
    TreeNode* q = root->right;    // Node 1
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    return 0;
}

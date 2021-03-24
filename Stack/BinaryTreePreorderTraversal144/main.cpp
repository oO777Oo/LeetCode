#include <iostream>
#include <vector>

using namespace std;

struct TreeNode;

vector<int> preorderTraversal(TreeNode *root);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> preorderTraversal(TreeNode *root) {
    vector<TreeNode*> stack = {root};
    vector<int> ans = {};

    while (!empty(stack)) {
        root = stack.back();
        stack.pop_back();
        if (root != nullptr) {
            ans.push_back(root->val);
            stack.push_back(root->right);
            stack.push_back(root->left);
        }
    }
    return ans;

}

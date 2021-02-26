#include <iostream>
#include <vector>

using namespace std;

struct TreeNode;
vector<int> inorderTraversal(TreeNode* root);


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



vector<int> inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return vector<int> {};
    }
    vector<TreeNode*> stack = {};
    vector<int> ans = {};
    TreeNode* node = root;

    while (node != nullptr || !empty(stack)) {
        while (node != nullptr) {
            stack.push_back(node);
            node = node->left;
        }
        node = stack.back();
        stack.pop_back();
        ans.push_back(node->val);
        node = node->right;
    }
    return ans;


}




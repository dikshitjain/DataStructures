#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Depth-First Search (DFS) Inorder Traversal
void dfsInorder(TreeNode* root) {
    if (!root) return;
    dfsInorder(root->left);
    std::cout << root->val << " ";
    dfsInorder(root->right);
}

// Depth-First Search (DFS) Preorder Traversal
void dfsPreorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    dfsPreorder(root->left);
    dfsPreorder(root->right);
}

// Depth-First Search (DFS) Postorder Traversal
void dfsPostorder(TreeNode* root) {
    if (!root) return;
    dfsPostorder(root->left);
    dfsPostorder(root->right);
    std::cout << root->val << " ";
}

// Breadth-First Search (BFS) Traversal
void bfs(TreeNode* root) {
    if (!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        std::cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Binary Tree Traversals
    std::cout << "DFS Inorder: ";
    dfsInorder(root);
    std::cout << std::endl;

    std::cout << "DFS Preorder: ";
    dfsPreorder(root);
    std::cout << std::endl;

    std::cout << "DFS Postorder: ";
    dfsPostorder(root);
    std::cout << std::endl;

    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    return 0;
}

Using shared_ptr:

#include <iostream>
#include <memory>
#include <queue>

struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Depth-First Search (DFS) Inorder Traversal
void dfsInorder(const std::shared_ptr<TreeNode>& root) {
    if (!root) return;
    dfsInorder(root->left);
    std::cout << root->val << " ";
    dfsInorder(root->right);
}

// Depth-First Search (DFS) Preorder Traversal
void dfsPreorder(const std::shared_ptr<TreeNode>& root) {
    if (!root) return;
    std::cout << root->val << " ";
    dfsPreorder(root->left);
    dfsPreorder(root->right);
}

// Depth-First Search (DFS) Postorder Traversal
void dfsPostorder(const std::shared_ptr<TreeNode>& root) {
    if (!root) return;
    dfsPostorder(root->left);
    dfsPostorder(root->right);
    std::cout << root->val << " ";
}

// Breadth-First Search (BFS) Traversal
void bfs(const std::shared_ptr<TreeNode>& root) {
    if (!root) return;
    std::queue<std::shared_ptr<TreeNode>> q;
    q.push(root);
    while (!q.empty()) {
        std::shared_ptr<TreeNode> curr = q.front();
        q.pop();
        std::cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

int main() {
    // Create a binary tree
    auto root = std::make_shared<TreeNode>(1);
    root->left = std::make_shared<TreeNode>(2);
    root->right = std::make_shared<TreeNode>(3);
    root->left->left = std::make_shared<TreeNode>(4);
    root->left->right = std::make_shared<TreeNode>(5);
    root->right->left = std::make_shared<TreeNode>(6);
    root->right->right = std::make_shared<TreeNode>(7);

    // Binary Tree Traversals
    std::cout << "DFS Inorder: ";
    dfsInorder(root);
    std::cout << std::endl;

    std::cout << "DFS Preorder: ";
    dfsPreorder(root);
    std::cout << std::endl;

    std::cout << "DFS Postorder: ";
    dfsPostorder(root);
    std::cout << std::endl;

    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;

    TreeNode(int val) : val(val) {}
};

// Depth-First Search (DFS) Preorder Traversal
void dfsPreorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    for (TreeNode* child : root->children) {
        dfsPreorder(child);
    }
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
        for (TreeNode* child : curr->children) {
            q.push(child);
        }
    }
}

int main() {
    // Create an N-ary tree
    TreeNode* root = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    root->children.push_back(node2);
    root->children.push_back(node3);
    node2->children.push_back(node4);
    node2->children.push_back(node5);

    // N-ary Tree Traversals
    std::cout << "DFS Preorder: ";
    dfsPreorder(root);
    std::cout << std::endl;

    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    return 0;
}

Using shared_ptr:

#include <iostream>
#include <memory>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    std::vector<std::shared_ptr<TreeNode>> children;

    TreeNode(int val) : val(val) {}
};

// Depth-First Search (DFS) Preorder Traversal
void dfsPreorder(const std::shared_ptr<TreeNode>& root) {
    if (!root) return;
    std::cout << root->val << " ";
    for (const auto& child : root->children) {
        dfsPreorder(child);
    }
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
        for (const auto& child : curr->children) {
            q.push(child);
        }
    }
}

int main() {
    // Create an N-ary tree
    auto root = std::make_shared<TreeNode>(1);
    auto node2 = std::make_shared<TreeNode>(2);
    auto node3 = std::make_shared<TreeNode>(3);
    auto node4 = std::make_shared<TreeNode>(4);
    auto node5 = std::make_shared<TreeNode>(5);
    root->children.push_back(node2);
    root->children.push_back(node3);
    node2->children.push_back(node4);
    node2->children.push_back(node5);

    // N-ary Tree Traversals
    std::cout << "DFS Preorder: ";
    dfsPreorder(root);
    std::cout << std::endl;

    std::cout << "BFS: ";
    bfs(root);
    std::cout << std::endl;

    return 0;
}

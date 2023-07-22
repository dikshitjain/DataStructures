class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def dfs_inorder(root):
    if not root:
        return
    dfs_inorder(root.left)
    print(root.val, end=" ")
    dfs_inorder(root.right)

def dfs_preorder(root):
    if not root:
        return
    print(root.val, end=" ")
    dfs_preorder(root.left)
    dfs_preorder(root.right)

def dfs_postorder(root):
    if not root:
        return
    dfs_postorder(root.left)
    dfs_postorder(root.right)
    print(root.val, end=" ")

def bfs(root):
    if not root:
        return
    queue = [root]
    while queue:
        node = queue.pop(0)
        print(node.val, end=" ")
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)

# Create a binary tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

# Binary Tree Traversals
print("DFS Inorder:", end=" ")
dfs_inorder(root)
print()

print("DFS Preorder:", end=" ")
dfs_preorder(root)
print()

print("DFS Postorder:", end=" ")
dfs_postorder(root)
print()

print("BFS:", end=" ")
bfs(root)
print()

Binary Tree Traversals:

DFS Inorder:

Time Complexity: O(N) - where N is the number of nodes in the binary tree.
Space Complexity: O(H) - where H is the height of the binary tree.
In the worst case, the space complexity can be O(N) for a skewed binary tree.

DFS Preorder:

Time Complexity: O(N) - where N is the number of nodes in the binary tree.
Space Complexity: O(H) - where H is the height of the binary tree.
In the worst case, the space complexity can be O(N) for a skewed binary tree.

DFS Postorder:

Time Complexity: O(N) - where N is the number of nodes in the binary tree.
Space Complexity: O(H) - where H is the height of the binary tree.
In the worst case, the space complexity can be O(N) for a skewed binary tree.

BFS:

Time Complexity: O(N) - where N is the number of nodes in the binary tree.
Space Complexity: O(W) - where W is the maximum width of the binary tree at any level.

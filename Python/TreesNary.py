class TreeNode:
    def __init__(self, val):
        self.val = val
        self.children = []

def dfs_preorder(root):
    if not root:
        return
    print(root.val, end=" ")
    for child in root.children:
        dfs_preorder(child)

def bfs(root):
    if not root:
        return
    queue = [root]
    while queue:
        node = queue.pop(0)
        print(node.val, end=" ")
        for child in node.children:
            queue.append(child)

# Create an N-ary tree
root = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(5)
root.children.append(node2)
root.children.append(node3)
node2.children.append(node4)
node2.children.append(node5)

# N-ary Tree Traversals
print("DFS Preorder:", end=" ")
dfs_preorder(root)
print()

print("BFS:", end=" ")
bfs(root)
print()

N-ary Tree Traversals:

DFS Preorder:

Time Complexity: O(N) - where N is the number of nodes in the N-ary tree.
Space Complexity: O(H) - where H is the height of the N-ary tree.
In the worst case, the space complexity can be O(N) for a skewed N-ary tree.

BFS:

Time Complexity: O(N) - where N is the number of nodes in the N-ary tree.
Space Complexity: O(W) - where W is the maximum width of the N-ary tree at any level.

Adding a value to the binary tree and N-ary tree:

Time Complexity: O(1) - as adding a node to the tree takes constant time.
Space Complexity: O(1) - as adding a node does not require any additional memory allocation.

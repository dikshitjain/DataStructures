class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, x):
        if x != self.parent[x]:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return  # Already in the same set

        # Union by rank (attach smaller rank tree under root of higher rank tree)
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

# Example usage:
uf = UnionFind(5)
uf.union(0, 1)
uf.union(1, 2)
uf.union(3, 4)

print("Find(0):", uf.find(0))  # Output: 0
print("Find(1):", uf.find(1))  # Output: 0
print("Find(2):", uf.find(2))  # Output: 0
print("Find(3):", uf.find(3))  # Output: 3
print("Find(4):", uf.find(4))  # Output: 3


Time Complexities:

Find: O(log n) (almost constant time with path compression)
Union: O(log n) (almost constant time with union by rank)

Space Complexity:

The space complexity of the Union-Find data structure is O(n),
where n is the number of elements in the disjoint sets.
The parent and rank lists take linear space in the worst case.

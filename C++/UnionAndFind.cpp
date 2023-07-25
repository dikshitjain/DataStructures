#include <iostream>
#include <vector>

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return; // Already in the same set
        }

        // Union by rank (attach smaller rank tree under root of higher rank tree)
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    UnionFind uf(5);

    uf.unionSet(0, 1);
    uf.unionSet(1, 2);
    uf.unionSet(3, 4);

    std::cout << "Find(0): " << uf.find(0) << std::endl; // Output: 0
    std::cout << "Find(1): " << uf.find(1) << std::endl; // Output: 0
    std::cout << "Find(2): " << uf.find(2) << std::endl; // Output: 0
    std::cout << "Find(3): " << uf.find(3) << std::endl; // Output: 3
    std::cout << "Find(4): " << uf.find(4) << std::endl; // Output: 3

    return 0;
}

Time Complexities:

Find: O(log n) (almost constant time with path compression)
Union: O(log n) (almost constant time with union by rank)

Space Complexity:

The space complexity of the Union-Find data structure is O(n),
where n is the number of elements in the disjoint sets.
The parent and rank vectors take linear space in the worst case.

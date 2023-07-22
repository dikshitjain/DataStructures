Undirected Graph:

from collections import deque

def bfs(graph, start):
    visited = [False] * len(graph)
    queue = deque()

    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

# Example usage:
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2, 4],
    4: [3]
}

start = 0
print("BFS traversal of undirected graph from node", start, ": ", end="")
bfs(graph, start)

Time Complexity:

The time complexity of BFS for an undirected graph is O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:

The space complexity of BFS is O(V), where V is the number of vertices.
This is because the space required for the queue and the visited array is proportional to the number of
vertices.

def dfs_helper(graph, visited, node):
    visited[node] = True
    print(node, end=" ")

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs_helper(graph, visited, neighbor)

def dfs(graph, start):
    visited = [False] * len(graph)
    dfs_helper(graph, visited, start)

# Example usage:
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2, 4],
    4: [3]
}

start = 0
print("DFS traversal of undirected graph from node", start, ": ", end="")
dfs(graph, start)


Sure! Here are the implementations of BFS and DFS for an undirected graph in Python:

Undirected Graph - BFS:
python
Copy code
from collections import deque

def bfs(graph, start):
    visited = [False] * len(graph)
    queue = deque()

    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

# Example usage:
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2, 4],
    4: [3]
}

start = 0
print("BFS traversal of undirected graph from node", start, ": ", end="")
bfs(graph, start)
Time Complexity:

The time complexity of BFS for an undirected graph is O(V + E), where V is the number of vertices and E is the number of edges.
Space Complexity:

The space complexity of BFS is O(V), where V is the number of vertices. This is because the space required for the queue and the visited array is proportional to the number of vertices.
Undirected Graph - DFS:
python
Copy code
def dfs_helper(graph, visited, node):
    visited[node] = True
    print(node, end=" ")

    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs_helper(graph, visited, neighbor)

def dfs(graph, start):
    visited = [False] * len(graph)
    dfs_helper(graph, visited, start)

# Example usage:
graph = {
    0: [1, 2],
    1: [0, 2, 3],
    2: [0, 1, 3],
    3: [1, 2, 4],
    4: [3]
}

start = 0
print("DFS traversal of undirected graph from node", start, ": ", end="")
dfs(graph, start)

Time Complexity:

The time complexity of DFS for an undirected graph is O(V + E), where V is the number of vertices and
E is the number of edges.

Space Complexity:

The space complexity of DFS is O(V), where V is the number of vertices.
This is because the space required for the recursion stack and the visited array is proportional to the
number of vertices.

Directed Graph:

from collections import deque

def bfs(graph, start):
    visited = [False] * len(graph)
    queue = deque()

    queue.append(start)
    visited[start] = True

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for neighbor in graph[node]:
            if not visited[neighbor]:
                queue.append(neighbor)
                visited[neighbor] = True

# Example usage:
graph = {
    0: [1, 2],
    1: [3],
    2: [1],
    3: [2, 4],
    4: []
}

start = 0
print("BFS traversal of directed graph from node", start, ": ", end="")
bfs(graph, start)

Time Complexity:

The time complexity of BFS for a directed graph is O(V + E), where V is the number of vertices
and E is the number of edges.

Space Complexity:

The space complexity of BFS is O(V), where V is the number of vertices.
This is because the space required for the queue and the visited array is proportional to the
number of vertices.

Directed Graphs

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for BFS traversal of directed graph
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {3};
    graph[3] = {4};

    int start = 0;
    cout << "BFS traversal of directed graph from node " << start << ": ";
    bfs(graph, start);

    return 0;
}

Time Complexity:

The time complexity of BFS for a directed graph is O(V + E), where V is the number of vertices
and E is the number of edges.

Space Complexity:

The space complexity of BFS is O(V), where V is the number of vertices.
This is because the space required for the queue and the visited array is proportional to the number
of vertices.

#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsHelper(graph, visited, neighbor);
        }
    }
}

void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dfsHelper(graph, visited, start);
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {2, 3};
    graph[2] = {3};
    graph[3] = {4};

    int start = 0;
    cout << "DFS traversal of directed graph from node " << start << ": ";
    dfs(graph, start);

    return 0;
}

Time Complexity:

The time complexity of DFS for a directed graph is O(V + E), where V is the number of vertices and
E is the number of edges.

Space Complexity:

The space complexity of DFS is O(V), where V is the number of vertices. This is because the space required
for the recursion stack and the visited array is proportional to the number of vertices.


Undirected Graphs:

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for BFS traversal of undirected graph
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 3};
    graph[3] = {1, 2, 4};
    graph[4] = {3};

    int start = 0;
    cout << "BFS traversal of undirected graph from node " << start << ": ";
    bfs(graph, start);

    return 0;
}

Time Complexity:

The time complexity of BFS for an undirected graph is O(V + E), where V is the number of vertices
and E is the number of edges.

Space Complexity:

The space complexity of BFS is O(V), where V is the number of vertices.
This is because the space required for the queue and the visited array is proportional to the
number of vertices.

#include <iostream>
#include <vector>
using namespace std;

void dfsHelper(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsHelper(graph, visited, neighbor);
        }
    }
}

void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    dfsHelper(graph, visited, start);
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> graph(n);
    graph[0] = {1, 2};
    graph[1] = {0, 2, 3};
    graph[2] = {0, 1, 3};
    graph[3] = {1, 2, 4};
    graph[4] = {3};

    int start = 0;
    cout << "DFS traversal of undirected graph from node " << start << ": ";
    dfs(graph, start);

    return 0;
}

Time Complexity:

The time complexity of DFS for an undirected graph is O(V + E), where V is the number of vertices
and E is the number of edges.

Space Complexity:

The space complexity of DFS is O(V), where V is the number of vertices. This is because the space
required for the recursion stack and the visited array is proportional to the number of vertices.

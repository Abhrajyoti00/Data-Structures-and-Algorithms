#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> createAdjacencyMatrix(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                adjMatrix[i][j] = isConnected[i][j];
                adjMatrix[j][i] = isConnected[i][j];
            }
        }

        return adjMatrix;
    }

    void dfs(int sv, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        cout<<sv<<" ";
        visited[sv] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (isConnected[sv][i] && !visited[i])
                dfs(i, isConnected, visited);
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> visited(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        return ans;
    }

    void bfs(int sv, vector<vector<int>> &adjMatrix, vector<bool> &visited)
    {
        queue<int> q;
        q.push(sv);
        visited[sv] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";

            for (int i = 0; i < adjMatrix.size(); i++)
            {
                if (adjMatrix[front][i] && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    bool isGraphConnected(vector<vector<int>> &adjMatrix)
    {
        int n = adjMatrix.size();
        vector<bool> visited(n, false);
        dfs(0, adjMatrix, visited);

        for (bool v : visited)
        {
            if (!v)
                return false;
        }
        return true;
    }

    // Function to find articulation points
    void findArticulationPoints(int u, vector<vector<int>> &adjMatrix, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &articulation)
    {
        static int time = 0; // Time of discovery

        int children = 0; // Count of children in DFS tree

        disc[u] = low[u] = ++time;

        for (int v = 0; v < adjMatrix.size(); ++v)
        {
            if (adjMatrix[u][v])
            {
                if (disc[v] == -1) // If v is not visited yet (not in DFS tree)
                {
                    children++;
                    parent[v] = u;
                    findArticulationPoints(v, adjMatrix, disc, low, parent, articulation);

                    low[u] = min(low[u], low[v]);

                    // Check if the subtree rooted with v has a connection to one of the ancestors of u
                    if (low[v] >= disc[u])
                        articulation[u] = true;
                }
                else if (v != parent[u])
                    low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findAndPrintArticulationPoints(vector<vector<int>> &adjMatrix)
    {
        int V = adjMatrix.size();
        vector<int> disc(V, -1);   // Discovery time of each vertex
        vector<int> low(V, -1);    // Earliest visited vertex (the vertex with minimum discovery time) that can be reached from subtree rooted with current vertex
        vector<int> parent(V, -1);  // Stores the parent in DFS tree
        vector<bool> articulation(V, false); // To mark articulation points

        // Call the recursive function to find articulation points
        for (int i = 0; i < V; i++)
            if (disc[i] == -1)
                findArticulationPoints(i, adjMatrix, disc, low, parent, articulation);

        // Print articulation points
        cout << "Articulation points: ";
        for (int i = 0; i < V; i++)
            if (articulation[i])
                cout << i << " ";
        cout << endl;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements row-wise:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "You entered:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Solution solution;
    vector<vector<int>> adjacencyMatrix = solution.createAdjacencyMatrix(matrix);

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (const auto &row : adjacencyMatrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    cout << "DFS: ";
    int n = adjacencyMatrix.size();
    vector<bool> visited(n, false);
    solution.dfs(0, adjacencyMatrix, visited);
    cout << endl;

    cout << "BFS: ";
    fill(visited.begin(), visited.end(), false); // Reset visited array
    solution.bfs(0, adjacencyMatrix, visited);
    cout << endl;

    cout << "Is the graph connected? " << (solution.isGraphConnected(adjacencyMatrix) ? "Yes" : "No") << endl;

    solution.findAndPrintArticulationPoints(adjacencyMatrix);

    cout << "Number of connected components: " << solution.findCircleNum(adjacencyMatrix) << endl;

    return 0;
}

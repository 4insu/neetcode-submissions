class Solution {
public:
    void utilityDfs(int src, const vector<vector<int>>& graph, vector<bool>& visited) {
        visited[src] = true;

        for (auto &x : graph[src]) {
            if (!visited[x]) {
                utilityDfs(x, graph, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int count = 0;

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                utilityDfs(i, graph, visited);
            }
        }

        return count;
    }
};

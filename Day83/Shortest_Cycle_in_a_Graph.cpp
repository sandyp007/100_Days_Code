//  https://leetcode.com/problems/shortest-cycle-in-a-graph/description/
class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 1001); 
        vector<vector<int>> graph(n);
        int minLength = 1001;
        
        for (vector<int> & edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (minLength == 3)
                break;
            if (visited[i] == 1001)
                dfs(graph, visited, i, -1, 0, minLength);
        }
                
        return minLength == 1001 ? -1 : minLength;
    }

    void dfs(vector<vector<int>>& graph, vector<int>& visited, int vertice, int parent, int length, int& cycle) {
        if (cycle == 3) // 3 is the shortest possible cycle. Do not proccess search if we already found such cycle
            return;

        visited[vertice] = length++;
        for (int next : graph[vertice]) {
            if (next == parent)
                continue;
            if (visited[next] > length)
                dfs(graph, visited, next, vertice, length, cycle);
            if ((length - visited[next]) > 1)
                cycle = min(cycle, (length - visited[next]));
        }
    }
};
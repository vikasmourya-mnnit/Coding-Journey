class Solution {
public:
    int dijkstra(int V, int src, int dest,
                 vector<vector<pair<int, int>>> &adj) {

        vector<int> dis(V, INT_MAX);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        dis[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int u = it.second;

            if (wt > dis[u]) continue;

            for (auto nbr : adj[u]) {
                int v = nbr.first;
                int edgeWt = nbr.second;

                if (wt + edgeWt < dis[v]) {
                    dis[v] = wt + edgeWt;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis[dest] == INT_MAX ? -1 : dis[dest];
    }

    int shortestPath(int V, int src, int dest,
                     vector<vector<int>> &edges) {

        vector<vector<pair<int, int>>> adj(V);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        return dijkstra(V, src, dest, adj);
    }
};
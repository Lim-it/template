    //dijkstra with prioirity queue. time complexity:O(ElogE)
    //N = size
    //adjacency list format: vector<vector<pair<int, int>>>
    //store each edge in the index of the source, first is end point, second is weight 
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    //int INF = 2e9;
    //vector<int> d(N, INF);  <- uncomment it if needed
    vector<bool> vis(n, false);
    pq.push({0, start);
    d[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for (auto [v, w] : adj[u]){
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
